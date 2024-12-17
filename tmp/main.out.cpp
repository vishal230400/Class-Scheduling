#define POST_ACTOR_COMPILER 1
#line 1 "/flow_compile/src/main.cpp"
#include <iostream>
#include <vector>
#include "flow/flow.h"
#include "flow/network.h"
#include "flow/IConnection.h"
#include "fdbrpc/FlowTransport.h"
#include "fdbrpc/fdbrpc.h"
#include "flow/TLSConfig.actor.g.h"

															#line 12 "/flow_compile/tmp/main.out.cpp"
namespace {
// This generated class is to be used only via addNumbers()
															#line 10 "/flow_compile/src/main.cpp"
template <class AddNumbersActor>
															#line 10 "/flow_compile/src/main.cpp"
class AddNumbersActorState {
															#line 19 "/flow_compile/tmp/main.out.cpp"
public:
															#line 10 "/flow_compile/src/main.cpp"
	AddNumbersActorState(Future<int> const& x,int const& y) 
															#line 10 "/flow_compile/src/main.cpp"
															#line 10 "/flow_compile/src/main.cpp"
		 : x(x),
															#line 10 "/flow_compile/src/main.cpp"
		   y(y)
															#line 28 "/flow_compile/tmp/main.out.cpp"
	{

	}
	~AddNumbersActorState() 
	{

	}
	int a_body1(int loopDepth=0) 
	{
		try {
															#line 11 "/flow_compile/src/main.cpp"
			StrictFuture<int> __when_expr_0 = x;
															#line 11 "/flow_compile/src/main.cpp"
			if (static_cast<AddNumbersActor*>(this)->actor_wait_state < 0) return a_body1Catch1(actor_cancelled(), loopDepth);
															#line 43 "/flow_compile/tmp/main.out.cpp"
			if (__when_expr_0.isReady()) { if (__when_expr_0.isError()) return a_body1Catch1(__when_expr_0.getError(), loopDepth); else return a_body1when1(__when_expr_0.get(), loopDepth); };
			static_cast<AddNumbersActor*>(this)->actor_wait_state = 1;
															#line 11 "/flow_compile/src/main.cpp"
			__when_expr_0.addCallbackAndClear(static_cast<ActorCallback< AddNumbersActor, 0, int >*>(static_cast<AddNumbersActor*>(this)));
															#line 48 "/flow_compile/tmp/main.out.cpp"
			loopDepth = 0;
		}
		catch (Error& error) {
			loopDepth = a_body1Catch1(error, loopDepth);
		} catch (...) {
			loopDepth = a_body1Catch1(unknown_error(), loopDepth);
		}

		return loopDepth;
	}
	int a_body1Catch1(Error error,int loopDepth=0) 
	{
		this->~AddNumbersActorState();
		static_cast<AddNumbersActor*>(this)->sendErrorAndDelPromiseRef(error);
		loopDepth = 0;

		return loopDepth;
	}
	int a_body1cont1(int const& value,int loopDepth) 
	{
															#line 12 "/flow_compile/src/main.cpp"
		if (!static_cast<AddNumbersActor*>(this)->SAV<int>::futures) { (void)(value + y); this->~AddNumbersActorState(); static_cast<AddNumbersActor*>(this)->destroy(); return 0; }
															#line 71 "/flow_compile/tmp/main.out.cpp"
		new (&static_cast<AddNumbersActor*>(this)->SAV< int >::value()) int(value + y);
		this->~AddNumbersActorState();
		static_cast<AddNumbersActor*>(this)->finishSendAndDelPromiseRef();
		return 0;

		return loopDepth;
	}
	int a_body1cont1(int && value,int loopDepth) 
	{
															#line 12 "/flow_compile/src/main.cpp"
		if (!static_cast<AddNumbersActor*>(this)->SAV<int>::futures) { (void)(value + y); this->~AddNumbersActorState(); static_cast<AddNumbersActor*>(this)->destroy(); return 0; }
															#line 83 "/flow_compile/tmp/main.out.cpp"
		new (&static_cast<AddNumbersActor*>(this)->SAV< int >::value()) int(value + y);
		this->~AddNumbersActorState();
		static_cast<AddNumbersActor*>(this)->finishSendAndDelPromiseRef();
		return 0;

		return loopDepth;
	}
	int a_body1when1(int const& value,int loopDepth) 
	{
		loopDepth = a_body1cont1(value, loopDepth);

		return loopDepth;
	}
	int a_body1when1(int && value,int loopDepth) 
	{
		loopDepth = a_body1cont1(std::move(value), loopDepth);

		return loopDepth;
	}
	void a_exitChoose1() 
	{
		if (static_cast<AddNumbersActor*>(this)->actor_wait_state > 0) static_cast<AddNumbersActor*>(this)->actor_wait_state = 0;
		static_cast<AddNumbersActor*>(this)->ActorCallback< AddNumbersActor, 0, int >::remove();

	}
	void a_callback_fire(ActorCallback< AddNumbersActor, 0, int >*,int const& value) 
	{
		#ifdef WITH_ACAC
		static constexpr ActorBlockIdentifier __identifier = UID(9578512156108914944UL, 107643746863906816UL);
		ActorExecutionContextHelper __helper(static_cast<AddNumbersActor*>(this)->activeActorHelper.actorID, __identifier);
		#endif // WITH_ACAC
		a_exitChoose1();
		try {
			a_body1when1(value, 0);
		}
		catch (Error& error) {
			a_body1Catch1(error, 0);
		} catch (...) {
			a_body1Catch1(unknown_error(), 0);
		}

	}
	void a_callback_fire(ActorCallback< AddNumbersActor, 0, int >*,int && value) 
	{
		#ifdef WITH_ACAC
		static constexpr ActorBlockIdentifier __identifier = UID(9578512156108914944UL, 107643746863906816UL);
		ActorExecutionContextHelper __helper(static_cast<AddNumbersActor*>(this)->activeActorHelper.actorID, __identifier);
		#endif // WITH_ACAC
		a_exitChoose1();
		try {
			a_body1when1(std::move(value), 0);
		}
		catch (Error& error) {
			a_body1Catch1(error, 0);
		} catch (...) {
			a_body1Catch1(unknown_error(), 0);
		}

	}
	void a_callback_error(ActorCallback< AddNumbersActor, 0, int >*,Error err) 
	{
		#ifdef WITH_ACAC
		static constexpr ActorBlockIdentifier __identifier = UID(5187328219730237440UL, 3113259079076601088UL);
		ActorExecutionContextHelper __helper(static_cast<AddNumbersActor*>(this)->activeActorHelper.actorID, __identifier);
		#endif // WITH_ACAC
		a_exitChoose1();
		try {
			a_body1Catch1(err, 0);
		}
		catch (Error& error) {
			a_body1Catch1(error, 0);
		} catch (...) {
			a_body1Catch1(unknown_error(), 0);
		}

	}
															#line 10 "/flow_compile/src/main.cpp"
	Future<int> x;
															#line 10 "/flow_compile/src/main.cpp"
	int y;
															#line 164 "/flow_compile/tmp/main.out.cpp"
};
// This generated class is to be used only via addNumbers()
															#line 10 "/flow_compile/src/main.cpp"
class AddNumbersActor final : public Actor<int>, public ActorCallback< AddNumbersActor, 0, int >, public FastAllocated<AddNumbersActor>, public AddNumbersActorState<AddNumbersActor> {
															#line 169 "/flow_compile/tmp/main.out.cpp"
public:
	using FastAllocated<AddNumbersActor>::operator new;
	using FastAllocated<AddNumbersActor>::operator delete;
	static constexpr ActorIdentifier __actorIdentifier = UID(2004859359143477760UL, 15383150472876360960UL);
	ActiveActorHelper activeActorHelper;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdelete-non-virtual-dtor"
    void destroy() override {
        activeActorHelper.~ActiveActorHelper();
        static_cast<Actor<int>*>(this)->~Actor();
        operator delete(this);
    }
#pragma clang diagnostic pop
friend struct ActorCallback< AddNumbersActor, 0, int >;
															#line 10 "/flow_compile/src/main.cpp"
	AddNumbersActor(Future<int> const& x,int const& y) 
															#line 186 "/flow_compile/tmp/main.out.cpp"
		 : Actor<int>(),
		   AddNumbersActorState<AddNumbersActor>(x, y),
		   activeActorHelper(__actorIdentifier)
	{
		#ifdef WITH_ACAC
		static constexpr ActorBlockIdentifier __identifier = UID(17236178018339221248UL, 10958314620478650368UL);
		ActorExecutionContextHelper __helper(static_cast<AddNumbersActor*>(this)->activeActorHelper.actorID, __identifier);
		#endif // WITH_ACAC
		#ifdef ENABLE_SAMPLING
		this->lineage.setActorName("addNumbers");
		LineageScope _(&this->lineage);
		#endif
		this->a_body1();

	}
	void cancel() override
	{
		auto wait_state = this->actor_wait_state;
		this->actor_wait_state = -1;
		switch (wait_state) {
		case 1: this->a_callback_error((ActorCallback< AddNumbersActor, 0, int >*)0, actor_cancelled()); break;
		}

	}
};
} // namespace
															#line 10 "/flow_compile/src/main.cpp"
[[nodiscard]] Future<int> addNumbers( Future<int> const& x, int const& y ) {
															#line 10 "/flow_compile/src/main.cpp"
	return Future<int>(new AddNumbersActor(x, y));
															#line 217 "/flow_compile/tmp/main.out.cpp"
}

#line 14 "/flow_compile/src/main.cpp"

int main() {
    auto tls = TLSConfig();
    g_network = newNet2(tls);

    // We compose our future chain.
    auto result1 = addNumbers(Future<int>(10),5);

    // Tell the network when it can stop: wait for both future chains to complete.
    auto r = stopAfter(waitForAll(std::vector<Future<int>>({result1})));
    if (r.isError()) {
        std::cout << "Something bad happened: " << r.getError().what() << std::endl;
    }

    // Start the network and wait for it to stop.
    g_network->run();

    // Check and print the results.
    if (result1.isReady()) {
        std::cout << "Result 1: " << result1.getValue() << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
        return 1;
    }
}
