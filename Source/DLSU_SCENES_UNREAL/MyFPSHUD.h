// MyFPSHUD.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyFPSHUD.generated.h"

UCLASS()
class YOURGAME_API AMyFPSHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

private:
    TArray<float> FrameTimes;
    float CalculateAverageFPS() const;
};