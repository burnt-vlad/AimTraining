// Aim Training Game. Fedosov Vladislav


#include "AccuracyPlayerState.h"

DEFINE_LOG_CATEGORY_STATIC(LogPlayerStat, All, All)

void AAccuracyPlayerState::PrintStat()
{
	UE_LOG(LogPlayerStat, Warning, TEXT("Shots: %i, Hits: %i"), ShotsNum, HitsNum);
}