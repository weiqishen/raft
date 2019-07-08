// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: raft.proto
#ifndef GRPC_raft_2eproto__INCLUDED
#define GRPC_raft_2eproto__INCLUDED

#include "raft.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc_impl {
class Channel;
class CompletionQueue;
class ServerCompletionQueue;
}  // namespace grpc_impl

namespace grpc {
namespace experimental {
template <typename RequestT, typename ResponseT>
class MessageAllocator;
}  // namespace experimental
}  // namespace grpc_impl

namespace grpc {
class ServerContext;
}  // namespace grpc

class Raft final {
 public:
  static constexpr char const* service_full_name() {
    return "Raft";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::RequestVoteReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>> AsyncRequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>>(AsyncRequestVoteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>> PrepareAsyncRequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>>(PrepareAsyncRequestVoteRaw(context, request, cq));
    }
    virtual ::grpc::Status AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::AppendEntriesReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>> AsyncAppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>>(AsyncAppendEntriesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>> PrepareAsyncAppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>>(PrepareAsyncAppendEntriesRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::RequestVoteReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::RequestVoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::AppendEntriesReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::AppendEntriesReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>* AsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::RequestVoteReply>* PrepareAsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>* AsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::AppendEntriesReply>* PrepareAsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::RequestVoteReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>> AsyncRequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>>(AsyncRequestVoteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>> PrepareAsyncRequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>>(PrepareAsyncRequestVoteRaw(context, request, cq));
    }
    ::grpc::Status AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::AppendEntriesReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>> AsyncAppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>>(AsyncAppendEntriesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>> PrepareAsyncAppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>>(PrepareAsyncAppendEntriesRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response, std::function<void(::grpc::Status)>) override;
      void RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::RequestVoteReply* response, std::function<void(::grpc::Status)>) override;
      void RequestVote(::grpc::ClientContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void RequestVote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::RequestVoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response, std::function<void(::grpc::Status)>) override;
      void AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::AppendEntriesReply* response, std::function<void(::grpc::Status)>) override;
      void AppendEntries(::grpc::ClientContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void AppendEntries(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::AppendEntriesReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>* AsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::RequestVoteReply>* PrepareAsyncRequestVoteRaw(::grpc::ClientContext* context, const ::RequestVoteRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>* AsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::AppendEntriesReply>* PrepareAsyncAppendEntriesRaw(::grpc::ClientContext* context, const ::AppendEntriesRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_RequestVote_;
    const ::grpc::internal::RpcMethod rpcmethod_AppendEntries_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response);
    virtual ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_RequestVote() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRequestVote(::grpc::ServerContext* context, ::RequestVoteRequest* request, ::grpc::ServerAsyncResponseWriter< ::RequestVoteReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_AppendEntries() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAppendEntries(::grpc::ServerContext* context, ::AppendEntriesRequest* request, ::grpc::ServerAsyncResponseWriter< ::AppendEntriesReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_RequestVote<WithAsyncMethod_AppendEntries<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_RequestVote() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::RequestVoteRequest, ::RequestVoteReply>(
          [this](::grpc::ServerContext* context,
                 const ::RequestVoteRequest* request,
                 ::RequestVoteReply* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->RequestVote(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_RequestVote(
        ::grpc::experimental::MessageAllocator< ::RequestVoteRequest, ::RequestVoteReply>* allocator) {
      static_cast<::grpc::internal::CallbackUnaryHandler< ::RequestVoteRequest, ::RequestVoteReply>*>(
          ::grpc::Service::experimental().GetHandler(0))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_AppendEntries() {
      ::grpc::Service::experimental().MarkMethodCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::AppendEntriesRequest, ::AppendEntriesReply>(
          [this](::grpc::ServerContext* context,
                 const ::AppendEntriesRequest* request,
                 ::AppendEntriesReply* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->AppendEntries(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_AppendEntries(
        ::grpc::experimental::MessageAllocator< ::AppendEntriesRequest, ::AppendEntriesReply>* allocator) {
      static_cast<::grpc::internal::CallbackUnaryHandler< ::AppendEntriesRequest, ::AppendEntriesReply>*>(
          ::grpc::Service::experimental().GetHandler(1))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_RequestVote<ExperimentalWithCallbackMethod_AppendEntries<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_RequestVote() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_AppendEntries() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_RequestVote() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRequestVote(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_AppendEntries() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestAppendEntries(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_RequestVote() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->RequestVote(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void RequestVote(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_AppendEntries() {
      ::grpc::Service::experimental().MarkMethodRawCallback(1,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->AppendEntries(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void AppendEntries(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_RequestVote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_RequestVote() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::RequestVoteRequest, ::RequestVoteReply>(std::bind(&WithStreamedUnaryMethod_RequestVote<BaseClass>::StreamedRequestVote, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_RequestVote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status RequestVote(::grpc::ServerContext* context, const ::RequestVoteRequest* request, ::RequestVoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedRequestVote(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::RequestVoteRequest,::RequestVoteReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_AppendEntries : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_AppendEntries() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::AppendEntriesRequest, ::AppendEntriesReply>(std::bind(&WithStreamedUnaryMethod_AppendEntries<BaseClass>::StreamedAppendEntries, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_AppendEntries() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status AppendEntries(::grpc::ServerContext* context, const ::AppendEntriesRequest* request, ::AppendEntriesReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedAppendEntries(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::AppendEntriesRequest,::AppendEntriesReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_RequestVote<WithStreamedUnaryMethod_AppendEntries<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_RequestVote<WithStreamedUnaryMethod_AppendEntries<Service > > StreamedService;
};


#endif  // GRPC_raft_2eproto__INCLUDED
