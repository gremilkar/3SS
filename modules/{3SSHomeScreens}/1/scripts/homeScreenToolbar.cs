//-----------------------------------------------------------------------------
// 3 Step Studio
// Copyright GarageGames, LLC 2012
//-----------------------------------------------------------------------------

/// <summary>
/// Loads the Asset Library
/// </summary>
function Hs_HomeButton::onClick(%this)
{
    ResetCommonToolButtons();
    %this.setStateOn(true);
    
    // Clear all the views from the shell
    EditorShellGui.clearViews();
    
    // Push the template selector view
    EditorShellGui.addView(TemplateListGui, "");
    EditorShellGui.addView(GamesLocationGui, "");
}

/// <summary>
/// Switches to the Exercises Page
/// </summary>
function Hs_ExercisesButton::onClick(%this)
{
    ResetCommonToolButtons();
    %this.setStateOn(true);
    
    // Clear all the views from the shell
    EditorShellGui.clearViews();
    
    // Push the exercises view
    EditorShellGui.addView(ExerciseListGui, "");
    EditorShellGui.addView(GamesLocationGui, "");
}

/// <summary>
/// Tests the current project
/// </summary>
function Hs_MyGamesButton::onClick(%this)
{
    ResetCommonToolButtons();
    %this.setStateOn(true);
    
    showAllGames();
}

function ResetCommonToolButtons()
{
    Hs_HomeButton.setStateOn(false);
    Hs_ExercisesButton.setStateOn(false);
    Hs_MyGamesButton.setStateOn(false);
}