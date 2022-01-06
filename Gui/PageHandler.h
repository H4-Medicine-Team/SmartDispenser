#pragma once
#include "Page.h"

#include <unordered_map>
#include <string>

namespace Gui {
	class PageHandler
	{
	private:
		PageHandler() : m_Pages(0), m_CurrentPage(NULL) {}

		~PageHandler() {
		}

	public:
		// Adds a page to the array, so that it can be set later
		inline void Add(Page* page, const std::string& name) {
			m_Pages.emplace(name, page);
		}

		// Sets the current page from the name given
		inline void SetPage(const std::string& name) {
			if (m_CurrentPage)
				m_CurrentPage->Unload();

			m_CurrentPage = m_Pages.find(name)->second;
			m_CurrentPage->Start();
		}

		// This method calls both update and draw
		inline void Loop() {
			m_CurrentPage->Update();
			m_CurrentPage->Draw();
		}

	private:
		std::unordered_map<std::string, Page*> m_Pages;
		Page* m_CurrentPage;

	// Singleton
	public:
		static PageHandler& Get() { static PageHandler instance; return instance; }
	};
}