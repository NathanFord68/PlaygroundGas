// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PlaygroundGas : ModuleRules
{
	public PlaygroundGas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] { 
			"PlaygroundGas"  // Allows us to organize our project into folders
		});

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"GameplayAbilities" // How we get GAS to be used in our project, without this none of it's includes will be found
		});
	}
}
