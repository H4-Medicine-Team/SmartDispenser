#pragma once
#include "Page.h"

#include <unordered_map>
#include <string>

namespace Gui {
	class PageHandler
	{
	public:
		inline void Add(Page* page, const std::string& name) {
			m_Pages.emplace(name, page);
		}

		inline void SetPage(const std::string& name) {
			m_CurrentPage = m_Pages.find(name)->second;
		}

		inline void Loop() {
			m_CurrentPage->Update();
			m_CurrentPage->Draw();
		}

	private:
		PageHandler() : m_Pages(0), m_CurrentPage(NULL) {}

		~PageHandler() {

		}
	private:
		std::unordered_map<std::string, Page*> m_Pages;
		Page* m_CurrentPage;

	// Singleton
	public:
		static PageHandler& Get() { static PageHandler instance; return instance; }
	};
}