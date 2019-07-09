//
// Created by Alex Chi on 2019-07-08.
//

#ifndef RAFT_INSTANCE_H
#define RAFT_INSTANCE_H

#include <string>
#include <map>
#include <google/protobuf/message.h>
#include <boost/optional.hpp>

#include "../utils/utils.h"
#include "LogStorage.h"
#include "MockRPCClient.h"

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using boost::optional;
using google::protobuf::Message;
using std::string;
using std::map;
using std::ostream;

enum Role {
    FOLLOWER = 0, CANDIDATE, LEADER
};

using Cluster = string;

class Instance {
public:
    unsigned int current_term;
    optional<const string> voted_for;
    LogStorage logs;
    Role role;
    const string id;
    shared_ptr<MockRPCClient> rpc;
    vector<Cluster> clusters;
    vector<Cluster> clusters_including_self;
    TICK follower_timeout;
    TICK follower_begin;
    TICK election_timeout;
    TICK election_begin;
    unsigned election_vote_cnt;
    map <Cluster, bool> voted_for_self;
    map <Cluster, unsigned int> next_index;
    map <Cluster, unsigned int> match_index;
    unsigned int commit_index;
    unsigned int last_applied;

    Instance(const string &id, shared_ptr<MockRPCClient> rpc);

    void start();

    void update();

    static TICK generate_timeout();

    void begin_election();

    void sync_log();

    void as_follower();

    void as_candidate();

    void as_leader();

    string get_role_string();

    void set_clusters(const vector<Cluster>& clusters);

    unsigned cluster_size();

    void on_rpc(const string& from, shared_ptr<Message> message);

    unsigned int get_term(shared_ptr<Message> message);

    void append_entry(const string& entry);
};


#endif //RAFT_INSTANCE_H
