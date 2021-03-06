#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "GUIConstants.h"

class LoginWindowComponent : public Component
{
public:
	LoginWindowComponent();
	~LoginWindowComponent();
    void resized() override;


private:
	TextEditor m_user_name;
	TextEditor m_password;
	TextButton m_btn;
	Label m_lbl_user_name;
	Label m_lbl_password;

};