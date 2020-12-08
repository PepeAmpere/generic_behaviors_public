#include "\vbs2\basic_defines.hpp"
#define __CurrentDir__ \core\addons\plugins\generic_behaviors_public

//Class necessary for VBS to load the new addon correctly
class CfgPatches
{
	class vbs2_vbs_plugins_generic_behaviors_public
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.10;
		requiredAddons[] = {
			vbs2_editor, 
			vbs2_people
		};
		modules[] =
		{
			vbs_core_content_module
		};
	};
};

// Adds btset to list of btsets which are loaded automatically
class CfgBehaviorTrees
{
	class generic_behaviors_public //this is an arbitrary className, it needs to be unique though
	{
		path = "\core\addons\plugins\generic_behaviors_public\data\generic_behaviors_public\generic_behaviors_public.btset"; //This is the relative path to the BT-set file to load
		name = "generic_behaviors_public"; // This is the btset name duplicated in the configuration
	};
};

class vbs_functions_base;
class CfgFunctions
{
	// Macro to build a function in sripts top folder
	#define MAKE_CORE_FUNCTION(functionName)                                 \
	class fn_vbs_generic_public_##functionName : vbs_functions_base                     \
	{                                                                       \
		path = __CurrentDir__\data\scripts\fn_vbs_generic_public__##functionName##.sqf;  \
	}

};

// formations
class CfgFormations
{
	class West
	{
		#include "cfgFormations.hpp"
	};

	class East : West
	{
		#include "cfgFormations.hpp"
	};

	class Civ : West
	{
		#include "cfgFormations.hpp"
	};

	class Guer : West
	{
		#include "cfgFormations.hpp"
	};
};

// Defines the new order as available from the Control AI - Military
class CfgAvailableBehaviors
{
	class generic_team_move_public
	{
		icon = "\core\addons\plugins\generic_behaviors_public\data\generic_team_move_public.paa";
		allowRotate = true;

		identity = "generic_team";
		displayname = "Public FT Move";
		description = "Public specific fireteam move";				

		//displayCondition = "\core\addons\plugins\generic_behaviors_public\data\scripts\waypointDisplayCondition.sqf";

		newOrderSubject = "NewOrder";
		
		class RootBehaviors
		{
			group[] = {"generic_behaviors_public", "genericRoot"};
			entity[] = {"generic_behaviors_public", "genericRoot"};
		};
		
		class Parameters
		{
			class orderName
			{
				displayName = "orderName";
				value = "move";
				type = "string";
			}
			class orderParameters
			{
				displayName = "orderParameters";
				value = "";
				type = "table";
			};
			class reportCompletedToExternal
			{
				displayName = "reportCompletedToExternal";
				value = "true";
				type = "boolean";
			};
			class debugEnabled
			{
				displayName = "debugEnabled";
				value = "false";
				type = "boolean";
			};
		};
	};
};
