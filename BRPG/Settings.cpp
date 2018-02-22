#include <fstream>
#include <string>

#include "Settings.h"


Settings::Settings()
{
	this->reader.open("settings.ini");
	Read();
}

Settings::~Settings()
{
	Write();
}

void Settings::Read()
{
	std::string settingName = "";
	int settingValue = 0;

	do
	{
		this->reader >> settingName >> settingValue;

		this->settings[settingName] = settingValue;
		
	} while (!(this->reader.eof()));

	this->reader.clear();
	this->reader.seekg(std::ios_base::beg);
}

void Settings::Write()
{
	std::ofstream writer("settings.ini");

	for (auto it = this->settings.begin(); it != this->settings.end(); it++)
		writer << it->first << " " << it->second << std::endl;

	this->reader.clear();
	this->reader.seekg(std::ios_base::beg);
}

int Settings::getSetting(std::string setting)
{
	return this->settings[setting];
}

void Settings::setSetting(std::string name, int value)
{
	this->settings[name] = value;
}

std::map<std::string, int> Settings::getSettingsArray()
{
	return this->settings;
}

void Settings::setSettingsArray(std::map<std::string, int> settingsArray)
{
	this->settings = settingsArray;

	Write();
	Read();
}
