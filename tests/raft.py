import logging
import unittest
import os
import subprocess
import toml
import signal
import time
import threading
import utils
import tempfile
import grpc

verbose = False
if os.environ.get("VERBOSE"):
    verbose = True

logging.basicConfig(level=os.environ.get("LOGLEVEL", "INFO"))
if not 'RAFT_EXECUTABLE' in os.environ:
    logging.error('raft service executable not found')
    exit()

executable = os.path.abspath(os.environ['RAFT_EXECUTABLE'])

logging.info('using raft service executable at \'%s\'' % executable)

logging.info('generating config...')

clusters = {"test1": "23333",
            "test2": "23334",
            "test3": "23335",
            "test4": "23336",
            "test5": "23337",
            "test6": "23338",
            "test7": "23339",
            "test8": "23340",
            "test9": "23341"}

default_clusters = ["test1", "test2", "test3", "test4", "test5"]
extra_clusters = ["test6", "test7", "test8", "test9"]

config = {"server": {}, "clusters": []}

_config_dir = tempfile.TemporaryDirectory()
config_dir = _config_dir.name

raft_threads = {}

for (k, v) in clusters.items():
    if k in default_clusters:
        config["clusters"].append({"name": k, "addr": "127.0.0.1:%s" % v})

def get_addr(id):
    return "127.0.0.1:%s" % clusters[id]


def config_file(id):
    return "%s/%s_config.toml" % (config_dir, id)


def generate_config():
    for (k, v) in clusters.items():
        config["server"]["name"] = k
        config["server"]["addr"] = "127.0.0.1:%s" % v
        dump_config = toml.dumps(config)
        f = open(config_file(k), "w")
        f.write(dump_config)
        f.close()
        logging.debug('config for %s generated' % k)

    logging.info('config generation complete')


def bootstrap_client(id, config_path):
    args = [executable, config_path]
    if verbose:
        args = [executable, config_path, "--verbose"]
    try:
        subprocess.run(args=args)
    except Exception as e:
        logging.warning("%s errored %s" % (id, e))
        # raise e
    logging.debug("%s detached" % id)
    raft_threads[id] = None


def spawn_client_thread(id):
    config_path = config_file(id)
    logging.debug('running %s with config %s' % (id, config_path))

    def bootstrap():
        thread = threading.Thread(
            target=bootstrap_client, args=(id, config_path,))
        raft_threads[id] = thread
        thread.start()
    bootstrap()
    restart_cnt = 30
    while True:
        restart_cnt = restart_cnt - 1
        if utils.is_alive(get_addr(id)) or restart_cnt < 0:
            break
        else:
            if raft_threads[id] is None:
                bootstrap()
                logging.warning("%s spawn failed, restarting..." % id)
    if restart_cnt < 0:
        logging.error("spawn failed")
        exit(-1)
    logging.debug("%s alive" % id)


def kick_off(id):
    if not (id in raft_threads):
        return
    utils.kick_off(get_addr(id), raft_threads[id])
    wait_dead(id)
    while True:
        if raft_threads[id] is None:
            break


def request_log(id):
    return utils.request_log(get_addr(id))


def append_log(id, log):
    return utils.append_log(get_addr(id), [log])


def append_logs(id, logs):
    return utils.append_log(get_addr(id), logs)


def find_role(clusters, role):
    result = []
    for k in clusters:
        try:
            log = request_log(k)
            if log.role == role:
                result.append(k)
        except grpc.RpcError:
            logging.warning("request to %s failed", k)

    return result


def find_leaders(clusters):
    return find_role(clusters, "leader")


def find_followers(clusters):
    return find_role(clusters, "follower")


def find_candidates(clusters):
    return find_role(clusters, "candidate")


def request_all_logs(clusters):
    logs = {}
    for k in clusters:
        try:
            logs[k] = request_log(k)
        except grpc.RpcError:
            logging.warning("request to %s failed", k)

    return logs


def wait_alive(id):
    utils.wait_alive(get_addr(id))


def wait_dead(id):
    utils.wait_dead(get_addr(id))


def offline(id):
    utils.offline(get_addr(id))


def online(id):
    utils.online(get_addr(id))


generate_config()
