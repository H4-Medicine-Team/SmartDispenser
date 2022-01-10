#pragma once
#include <vector>
#include <functional>
#include <string>
#include <iostream>

namespace UnitTest {

	struct AssertOutput {
		AssertOutput(const std::string& title, const std::string& name, bool success_) :
			testTitle(title),
			testName(name),
			success(success_)
		{};

		std::string testTitle;
		std::string testName;
		bool success = false;
	};

	class TestCase {
	public:
		TestCase(const std::string& title, const std::string& name)
		:	m_Output(),
			m_Title(title),
			m_Name(name)
		{};

		~TestCase() {};

		const std::vector<AssertOutput>& GetTestCases() { Case(); return m_Output; }

	protected:

		virtual void Case() = 0;

		void AddAssert(const AssertOutput& assert) { m_Output.push_back(assert); }

		const std::string& GetName() {
			return m_Name;
		}

		const std::string& GetTitle() {
			return m_Title;
		}

	private:
		std::vector<AssertOutput> m_Output;
		std::string m_Name;
		std::string m_Title;
	};

	class TestFramework {
	public:
		static TestFramework& Get() {
			static TestFramework instance;
			return instance;
		}

		TestFramework(TestFramework const&) = delete;
		void operator=(TestFramework const&) = delete;

		TestFramework()
		: m_Tests() {};


		~TestFramework() {};

		template<typename T>
		inline bool AddTests() {
			TestCase* testCase = new T();
			const std::vector<AssertOutput>& v = testCase->GetTestCases();

			for (int i = 0; i < v.size(); i++)
				m_Tests.push_back(v[i]);

			delete testCase;

			return true;
		}

		inline void Run() {
			// Search all cpp files

			// run tests
			for (int i = 0; i < m_Tests.size(); i++)
				Log(&m_Tests[i]);
		}

	private:
		inline void Log(AssertOutput* output) {
			char* message = new char[200];
			sprintf(message, "[%s::%s] [%s]", output->testTitle.c_str(), output->testName.c_str(), output->success ? "SUCCESS" : "FAILED");

			if (output->success)
				std::cout << "\033[32m" << message << std::endl;
			else
				std::cout << "\033[31m" << message << std::endl;
		}
	private:
		std::vector<AssertOutput> m_Tests;
	};


#define ASSERT(CONDITION) \
    AddAssert({ \
    GetTitle(), \
    GetName(), \
    CONDITION, \
});

//class t : public UnitTest::TestCase {
//public:
//	t() : TestCase("Hej", "") {};
//protected:
//	virtual void Case() override;
//private:
//	static const bool registered_;
//};
//
//const bool t::registered_ = UnitTest::TestFramework::Get().AddTests<t>();
//void t::Case() {};


#define TESTCLASS_(TITLE, CASE) \
class TITLE ## CASE : public UnitTest::TestCase { \
private: \
	static const bool registered_; \
public: \
	TITLE ## CASE () : TestCase(#TITLE, #CASE) {} \
protected: \
    virtual void Case() override; };\
const bool TITLE ## CASE::registered_ = UnitTest::TestFramework::Get().AddTests<TITLE ## CASE>(); \
void TITLE ## CASE::Case()


#define TESTCASE(TITLE, CASE) TESTCLASS_(TITLE, CASE)
	

	
}