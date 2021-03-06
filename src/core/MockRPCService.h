//
// Created by Alex Chi on 2019-07-08.
//

#ifndef RAFT_MOCKRPCSERVICE_H
#define RAFT_MOCKRPCSERVICE_H

#include <memory>
#include <string>
#include <vector>

#include "RPC.h"

using std::shared_ptr;
using std::unique_ptr;
using std::string;
using std::vector;
using std::pair;
using google::protobuf::Message;

class RPCClient;

class MockRPCService {
public:
    struct RPCMessage {
        const string from, to;
        shared_ptr<Message> message;

        RPCMessage(const string &from, const string &to, shared_ptr<Message> message)
                : from(from), to(to), message(message) {}
    };

    MockRPCService();

    on_rpc_cb callback;

    vector<RPCMessage> message_queue;

    shared_ptr<RPCClient> get_client(const string &sender);

    void send(const string &from, const string &to, shared_ptr<Message> message);

    void set_callback(on_rpc_cb callback);
};

using std::ostream;

void log_message(const string& from, const string& to, shared_ptr<Message> message);

#endif //RAFT_MOCKRPCSERVICE_H
