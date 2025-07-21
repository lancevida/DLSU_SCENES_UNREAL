// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class DLSU_SCENES_UNREALTarget : TargetRules
{
	public DLSU_SCENES_UNREALTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DLSU_SCENES_UNREAL" } );
	}
}
