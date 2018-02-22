#pragma once

#include <string>
#include <fstream>
#include <map>

class Settings
{
	public:
		Settings();
		~Settings();
		void Read();
		void Write();
		int getSetting(std::string name);
		void setSetting(std::string name, int value);
		std::map<std::string, int> getSettingsArray();
		void setSettingsArray(std::map<std::string, int> settingsArray);

	private:
		std::map<std::string, int> settings;
		std::ifstream reader;
};