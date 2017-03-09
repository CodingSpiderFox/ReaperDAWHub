#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "ProjectEntryListComponent.h"
#include "LocalProjectEntryComponent.h"

class ProjectBrowserTabComponent : public TabbedComponent
{
public:
	ProjectBrowserTabComponent();
	~ProjectBrowserTabComponent();

private:

	ProjectEntryListComponent m_remote_proj;
	ProjectEntryListComponent m_local_proj;
	ProjectEntryComponent m_entry1;
	LocalProjectEntryComponent m_entry2;
};