// Aim Training Game. Fedosov Vladislav


#include "ReactionTimerWidget.h"
#include "AimTrainingProject/GameModes/ReactionGameMode.h"

int32 UReactionTimerWidget::GetTimeRemaining() const
{
	const auto ReactionGameMode = GetReactionGameMode();
	return ReactionGameMode ? ReactionGameMode->GetRoundCountDown() : 0;
}

AReactionGameMode* UReactionTimerWidget::GetReactionGameMode() const
{
	return GetWorld() ? Cast<AReactionGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;
}