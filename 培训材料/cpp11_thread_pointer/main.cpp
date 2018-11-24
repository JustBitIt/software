#include <iostream>
#include <thread>

void thread_function()
{
	for (int i = 0; i < 1000; i++)
		std::cout << "thread function Executing" << std::endl;
}

int main()
{
	std::thread threadObj(thread_function);
	for (int i = 0; i < 1000; i++)
		std::cout << "Display From MainThread" << std::endl;
	threadObj.join();
	std::cout << "Exit of Main function" << std::endl;
	system("pause");
	return 0;
}



//int main()
//{
//	int x = 9;
//	//std::function<void()> callable = [] {
//	//	for (int i = 0; i < 1000; i++)
//	//		std::cout << "Display Thread Executing" << std::endl;
//	//};
//
//	//std::thread threadObj(callable);
//
//	std::thread threadObj([] {
//		for (int i = 0; i < 10000; i++)
//			std::cout << "Display Thread Executing" << std::endl;
//	});
//
//	for (int i = 0; i < 1000; i++)
//		std::cout << "Display From Main Thread" << std::endl;
//
//	threadObj.join();
//	std::cout << "Exiting from Main Thread" << std::endl;
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <thread>
//void threadCallback(const int  & x)
//{
//	int & y = const_cast<int &>(x);
//	y++;
//	std::cout << "Inside Thread x = " << x << std::endl;
//}
//int main()
//{
//	int x = 9;
//	std::cout << "In Main Thread : Before Thread Start x = " << x << std::endl;
//	std::thread threadObj(threadCallback, x);
//	threadObj.join();
//	std::cout << "In Main Thread : After Thread Joins x = " << x << std::endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <thread>
//void threadCallback(int const & x)
//{
//	int & y = const_cast<int &>(x);
//	y++;
//	std::cout << "Inside Thread x = " << x << std::endl;
//}
//int main()
//{
//	int x = 9;
//	std::cout << "In Main Thread : Before Thread Start x = " << x << std::endl;
//	std::thread threadObj(threadCallback, std::ref(x));
//	threadObj.join();
//	std::cout << "In Main Thread : After Thread Joins x = " << x << std::endl;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <thread>
//class DummyClass {
//public:
//	DummyClass()
//	{}
//	DummyClass(const DummyClass & obj)
//	{}
//	void sampleMemberFunction(int x)
//	{
//		std::cout << "Inside sampleMemberFunction " << x << std::endl;
//	}
//};
//int main() {
//
//	DummyClass dummyObj;
//	int x = 10;
//	std::thread threadObj(&DummyClass::sampleMemberFunction, &dummyObj, x);
//	threadObj.join();
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <thread>
//#include <vector>
//// #include<mutex>
//class Wallet
//{
//	int mMoney;
//	//std::mutex mutex;
//public:
//	Wallet() :mMoney(0) {}
//	int getMoney() { return mMoney; }
//	void addMoney(int money)
//	{
//		//std::lock_guard<std::mutex> lockGuard(mutex);
//		//mutex.lock();
//		for (int i = 0; i < money; ++i)
//		{
//			mMoney++;
//		}
//		//mutex.unlock();
//	}
//};
//int testMultithreadedWallet()
//{
//	Wallet walletObject;
//	std::vector<std::thread> threads;
//	for (int i = 0; i < 5; ++i) {
//		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
//	}
//
//	for (int i = 0; i < threads.size(); i++)
//	{
//		threads.at(i).join();
//	}
//	return walletObject.getMoney();
//}
//
//int main()
//{
//
//	int val = 0;
//	for (int k = 0; k < 3000; k++)
//	{
//		if ((val = testMultithreadedWallet()) != 5000)
//		{
//			std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <functional>
//#include <mutex>
//#include <condition_variable>
////using namespace std::placeholders;
//class Application
//{
//	std::mutex m_mutex;
//	std::condition_variable m_condVar;
//	bool m_bDataLoaded;
//public:
//	Application()
//	{
//		m_bDataLoaded = false;
//	}
//	void loadData()
//	{
//		// Make This Thread sleep for 1 Second
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//		std::cout << "Loading Data from XML" << std::endl;
//		// Lock The Data structure
//		std::lock_guard<std::mutex> guard(m_mutex);
//		// Set the flag to true, means data is loaded
//		m_bDataLoaded = true;
//		// Notify the condition variable
//		m_condVar.notify_one();
//	}
//	bool isDataLoaded()
//	{
//		return m_bDataLoaded;
//	}
//	void mainTask()
//	{
//		std::cout << "Do Some Handshaking" << std::endl;
//		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//		// Acquire the lock
//		std::unique_lock<std::mutex> mlock(m_mutex);
//		// Start waiting for the Condition Variable to get signaled
//		// Wait() will internally release the lock and make the thread to block
//		// As soon as condition variable get signaled, resume the thread and
//		// again acquire the lock. Then check if condition is met or not
//		// If condition is met then continue else again go in wait.
//		m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
//		std::cout << "Do Processing On loaded Data" << std::endl;
//	}
//};
//int main()
//{
//	Application app;
//	std::thread thread_1(&Application::mainTask, &app);
//	std::thread thread_2(&Application::loadData, &app);
//	thread_2.join();
//	thread_1.join();
//	system("pause");
//	return 0;
//}
