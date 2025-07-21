
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSDisplayHUD.generated.h"

UCLASS()
class YOURGAME_API AFPSDisplayHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

private:
    TArray<float> FPSHistory;
    int32 MaxHistorySize = 100;
    float MaxExpectedFPS = 120.0f;

    void DrawAverageFPS(float AvgFPS);
    void DrawFPSGraph();
    float CalculateAverageFPS() const;
};