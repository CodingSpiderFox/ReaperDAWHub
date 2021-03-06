/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/
#define JUCE_DEBUG 0
#define WIN32_LEAN_AND_MEAN
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../includes/GUIDemo.h"
#include "../../ReaperDAWHub.GUI/includes/LoginWindow.h"
#include "../../ReaperDAWHub.GUI/includes/ProjectBrowserComponent.h"


//==============================================================================
class NewProjectApplication : public JUCEApplication
{
public:
	//==============================================================================
	NewProjectApplication() {
	}

	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	//==============================================================================
	void initialise(const String& commandLine) override
	{
		// This method is where you should put your application's initialisation code..

		mainWindow = new MainWindow(getApplicationName());
		projectBrowserWindow = new ProjectBrowserWindow(getApplicationName());
	}

	void shutdown() override
	{
		// Add your application's shutdown code here..

		mainWindow = nullptr; // (deletes our window)
		projectBrowserWindow = nullptr;
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}

	void anotherInstanceStarted(const String& commandLine) override
	{
		// When another instance of the app is launched while this one is running,
		// this method is invoked, and the commandLine parameter tells you what
		// the other instance's command-line arguments were.
	}

	//==============================================================================
	/*
	This class implements the desktop window that contains an instance of
	our MainContentComponent class.
	*/
	class MainWindow : public DocumentWindow
	{
	public:
		MainWindow(String name) : DocumentWindow(name,
			Colours::lightgrey,
			DocumentWindow::allButtons)
		{
			setUsingNativeTitleBar(true);
			setContentOwned(new LoginWindowComponent(), true);
			
			
			centreWithSize(getWidth(), getHeight());
			setVisible(true);
		}

		void closeButtonPressed() override
		{
			// This is called when the user tries to close this window. Here, we'll just
			// ask the app to quit when this happens, but you can change this to do
			// whatever you need.
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

		/* Note: Be careful if you override any DocumentWindow methods - the base
		class uses a lot of them, so by overriding you might break its functionality.
		It's best to do all your work in your content component instead, but if
		you really have to override any DocumentWindow methods, make sure your
		subclass also calls the superclass's method.
		*/

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

	class ProjectBrowserWindow : public DocumentWindow
	{
	public:
		ProjectBrowserWindow(String name) : DocumentWindow(name,
			Colours::lightgrey,
			DocumentWindow::allButtons)
		{
			setUsingNativeTitleBar(true);
			pc = new ProjectBrowserComponent();
			setContentOwned(pc, true);		


			centreWithSize(getWidth(), getHeight());
			setVisible(true);
		}

		void closeButtonPressed() override
		{
			// This is called when the user tries to close this window. Here, we'll just
			// ask the app to quit when this happens, but you can change this to do
			// whatever you need.
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

		/* Note: Be careful if you override any DocumentWindow methods - the base
		class uses a lot of them, so by overriding you might break its functionality.
		It's best to do all your work in your content component instead, but if
		you really have to override any DocumentWindow methods, make sure your
		subclass also calls the superclass's method.
		*/
		void init() {
		}
	private:
		ProjectBrowserComponent *pc;
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProjectBrowserWindow)
	};

private:
	ScopedPointer<MainWindow> mainWindow;
	ScopedPointer<ProjectBrowserWindow> projectBrowserWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(NewProjectApplication)
