class CfgPatches
{
	class SchanaModExpansionChatRCon
	{
		requiredAddons[] = {
			"DayZExpansionChat"
		};
		units[] = {};
		weapons[] = {};
	};
};

class CfgMods
{
	class SchanaModExpansionChatRCon
	{
		name = "SchanaModExpansionChatRCon";
		action = "https://github.com/schana/dayz-mod-expansion-chat-rcon";
		author = "schana";
		type = "mod";
		dependencies[] =
		{
			"Game",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				files[] =
				{
					"SchanaModExpansionChatRCon/Game"
				};
			};
			class missionScriptModule
			{
				files[] = {
					"SchanaModExpansionChatRCon/Mission"
				};
			};
		};
	};
};
