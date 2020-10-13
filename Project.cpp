#include "AoBlib.h"

int main()
{
    txCreateWindow(MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txClear();

    int xHero = 500;
    int yHero = 500;

    int acceleration = 1;
    int positionGrafic = 1;
    int phaseSecret = 0;
    int developerMonologueNumber = 0;
    enum DirectionSecret directionSecret = MOVE_UP;
    bool firstBugInGame = true;
    bool normalGame = true;
    int numberColorInFakeMenu = 1;

    struct Bridge {
        int xLeft = 400;
        int yLeft = 400;
        bool state = false;
        bool hero = false;
    };

    Bridge bridgesInMechanic[5][3] = {};

    for (int i=0; i<LINE_Y; ++i)
    {
        for (int j=0; j<LINE_X; ++j)
        {
            bridgesInMechanic[i][j].xLeft = 200 + 200*j;
            bridgesInMechanic[i][j].yLeft = 0 + 200*i;
        }
    }

    bool heroInPuddle = false;

    Bridge bridgeInMenu;

    Bridge bridgesInGrafic[QUANTITY_BRIDGES_IN_GRAFIC];
    bridgesInGrafic[0].xLeft = 800;
    bridgesInGrafic[0].yLeft = 550;
    bridgesInGrafic[1].xLeft = 350;
    bridgesInGrafic[1].yLeft = 550;
    bridgesInGrafic[2].xLeft = 0;
    bridgesInGrafic[2].yLeft = 300;

    Bridge bridgesInSecret[QUANTITY_BRIDGES_IN_SECRET];
    bridgesInSecret[0].xLeft = 500;
    bridgesInSecret[0].yLeft = 400;
    bridgesInSecret[1].xLeft = 600;
    bridgesInSecret[1].yLeft = 400;
    bridgesInSecret[2].xLeft = 250;
    bridgesInSecret[2].yLeft = 400;

    Bridge bridgesInStory[QUANTITY_BRIDGES_IN_STORY];
    bridgesInStory[0].xLeft = 200;
    bridgesInStory[0].yLeft = 550;
    bridgesInStory[1].xLeft = 600;
    bridgesInStory[1].yLeft = 550;

    Bridge bridgesInFirstRiverInTheGame [QUANTITY_BRIDGES_IN_SECOND_RIVER];

    for (int i=0; i<QUANTITY_BRIDGES_IN_SECOND_RIVER; ++i)
    {
        bridgesInFirstRiverInTheGame[i].xLeft = 200+200*i;
        bridgesInFirstRiverInTheGame[i].yLeft = 400;
    }

    int levelInSecret = 0;
    int secretSituation = 1;

    enum DirectionHero directionHeroWithGrafic = DOWN;

    int updatesOrder = 0;
    enum Updates updatesSequence[4];
    updatesSequence[0] = SECRETS;//delete

    bool menu = true; //true
    bool startPlace = false;
    bool graficPlace = false;
    bool mechanicPlace = false;
    bool secretPlace = false;
    bool storyPlace = false;

    bool fakeMenu = true; //true
    bool fakeGame = false;
    bool fakeLoose = false;

    bool beginningInTheGame = false;
    bool forkInTheGame = false;
    bool townInTheGame = false;
    bool firstRiverInTheGame = false;
    bool secondRiverInTheGame = false;
    bool secretPlaceInTheGame = false;
    bool placeOfGreed = false;
    bool theEndPlace = false;


    bool secretInGraficPlace = true;
    bool secretInMechanicPlace = true;
    bool secretInSecretPlace = true;
    bool secretInStoryPlace = true;

    bool graficUpdate = false;
    bool mechanicUpdate = false;
    bool secretUpdate = false;
    bool storyUpdate = false;


    bool fakeExit = false;
    bool deleteFakeExit = false;

    int secrets = 0; //0
    int bridgeInGame = 0; //0
    int xForFakeGame = 0;
    int stepInFakeGame = 0;
    int accelerationInFakeGame = 5;
    int xLoading = 600;
    int yLoading = 500;

    //ƒË‡ÎÓ„Ó‚˚Â ÒÓ·˚ÚËˇ
    bool firstGameStart = true;
    bool firstGameFork = true;
    bool returnInStart = false;
    bool firstStoneWithoutPickaxe = true;
    bool stayNearStone = true;
    bool stayNearCarpenter = true;
    bool stayNearError = true;
    bool stayNearWorker = true;
    bool stayNearMiner = true;
    bool firstGameRiver = true;
    bool firstGameTown = true;
    bool firstPlaceOfGreed = true;
    bool firstMeetingWithAdvertistingContract = true;
    bool thinkingAboutAdvertising = false;
    bool firstMeetingWithCarpenter = true;
    bool firstTalkWithCarpenterAboutStone = true;
    bool firstTalkWithCarpenterAboutError = true;
    bool firstTalkWithCarpenterAboutWorker = true;
    bool firstTalkWithCarpenterAboutMiner = true;
    bool firstSeeNewBridge = true;
    bool firstMeetingWithError = true;
    bool secondRiverGame = true;
    bool firstMeetingWithWorker = true;
    bool firstTalkWithWorkerAboutCarpenter = true;
    bool firstTalkWithWorkerAboutError = true;
    bool firstTalkWithWorkerAboutMiner = true;
    bool firstMeetingWithMiner = true;
    bool firstTalkWithMinerAboutCarpenter = true;
    bool firstTalkWithMinerAboutError = true;
    bool firstTalkWithMinerAboutWorker = true;
    bool firstStayInEmptyLootPlace = true;
    bool firstStayInLootPlaceWithChest = true;
    bool meetingWithChestWithQuest = true;
    bool destroyRock = false;
    bool heroWentTroughFence = true;
    bool firstComesInSecretPlaceInGame = true;
    bool secretInSecretPlaceInTheGame = true;
    bool heroFirstSeeSecretBridge = true;

    //œÂ‰ÏÂÚ˚
    bool adveristingContract = false;
    bool doingQuestFromMiner = false;
    bool completeQuestFromMiner = false;
    bool pickaxe = false;

    while(normalGame)
    {
        if (menu)
        {
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
            txSetFillColor(TX_WHITE);
            txRectangle(300, 100, 700, 300);
            txRectangle(300, 400, 700, 600);
            txRectangle(300, 700, 700, 900);
            txSelectFont("Arial", 90, 20);
            if (txMouseX()>300 and txMouseX()<700 and txMouseY()>100 and txMouseY()<300)
            {
                txSelectFont("Arial", 120, 30, 1000);
                if (txMouseButtons()==1)
                {
                    play();
                    menu = false;
                    startPlace = true;
                }
            }
            txDrawText(300, 150, 700, 250, "»„‡Ú¸");
            txSelectFont("Arial", 90, 20);
            if (txMouseX()>300 and txMouseX()<700 and txMouseY()>400 and txMouseY()<600)
            {
                txSelectFont("Arial", 120, 30, 1000);
                txDrawText(300, 450, 700, 550, "”Ô‡‚ÎÂÌËÂ");
                if (txMouseButtons()==1)
                {
                    training();
                }
            }
            txDrawText(300, 450, 700, 550, "”Ô‡‚ÎÂÌËÂ");
            txSelectFont("Arial", 90, 20);
            if (txMouseX()>300 and txMouseX()<700 and txMouseY()>700 and txMouseY()<900)
            {
                txSelectFont("Arial", 120, 30, 1000);
                if (txMouseButtons()==1)
                {
                    exit();
                }
            }
            txDrawText(300, 750, 700, 850, "¬˚ıÓ‰");
        }

        if (startPlace)
        {
            if (!graficUpdate)
            {
                drawStartPlaceWithoutGrafics();
            }
            else
            {
                drawStartPlaceWithGrafics();
            }

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if(((yHero<425 or yHero>575) and xHero-5*acceleration<425) or
                (secretUpdate and xHero-5*acceleration<LEFT_X) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if(((yHero<425 or yHero>575) and xHero+5*acceleration>575) or
                (mechanicUpdate and xHero+5*acceleration>RIGHT_X) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if(((xHero<425 or xHero>575) and yHero-5*acceleration<425) or
                (graficUpdate and yHero-5*acceleration<UP_Y) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if(((xHero<425 or xHero>575) and yHero+5*acceleration>575) or
                (storyUpdate and yHero+5*acceleration>DOWN_Y) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if(mechanicUpdate)
            {
                if (!graficUpdate)
                {
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                }
                else
                {
                    drawPuddle(350, 350, 650, 650);
                    drawWave(400, 400);
                    drawWave(500, 370);
                    drawWave(600, 600);
                    drawWave(520, 540);
                    drawWave(490, 580);
                    drawWave(370, 480);
                    drawWave(450, 530);
                    drawWave(470, 450);
                    drawWave(360, 600);
                    drawWave(600, 390);
                    drawWave(590, 480);
                }
                if (txMouseX()>bridgeInMenu.xLeft and txMouseY()>bridgeInMenu.yLeft and txMouseX()<bridgeInMenu.xLeft+200 and txMouseY()<bridgeInMenu.yLeft+200)
                {
                    if (!graficUpdate)
                    {
                        txSetFillColor(TX_WHITE);
                        txSetColor(TX_WHITE);
                    }
                    else
                    {
                        drawBridge(bridgeInMenu.xLeft, bridgeInMenu.yLeft);
                    }
                    bridgeInMenu.state = true;
                }
                else
                {
                    bridgeInMenu.state = false;
                }

                if (!graficUpdate)
                {
                    txRectangle(bridgeInMenu.xLeft+2, bridgeInMenu.yLeft+2, bridgeInMenu.xLeft+198, bridgeInMenu.yLeft+198);
                }

                if (xHero+60>bridgeInMenu.xLeft and yHero+60>bridgeInMenu.yLeft and xHero-60<bridgeInMenu.xLeft+200 and yHero-60<bridgeInMenu.yLeft+200 and bridgeInMenu.state==false)
                {
                    heroInPuddle = true;
                }
                if (xHero+60>bridgeInMenu.xLeft and yHero+60>bridgeInMenu.yLeft and xHero-60<bridgeInMenu.xLeft+200 and yHero-60<bridgeInMenu.yLeft+200 and bridgeInMenu.state==true)
                {
                    heroInPuddle = false;
                }
            }

            if (yHero<MIN_Y and graficUpdate==false)
            {
                graficPlace = true;
                startPlace = false;
                xHero = CENTER_X;
                yHero = 925;
            }

            if (xHero>MAX_X and mechanicUpdate==false)
            {
                mechanicPlace = true;
                startPlace = false;
                xHero = 75;
                yHero = CENTER_Y;
            }

            if (xHero<MIN_X and secretUpdate==false)
            {
                secretPlace = true;
                startPlace = false;
                levelInSecret = 1;
                xHero = 925;
                yHero = CENTER_Y;
            }

            if (yHero>MAX_Y and storyUpdate==false)
            {
                storyPlace = true;
                startPlace = false;
                xHero = CENTER_X;
                yHero = 75;
            }

            if (!graficUpdate)
            {
                drawHeroWithoutGrafics (xHero, yHero, heroInPuddle);
            }
            else
            {
                drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);
            }
        }

        if (graficPlace)
        {
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<LEFT_X) or
                (positionGrafic==1 and yHero>=825 and xHero-5*acceleration<475) or
                (yHero>325 and yHero<825 and xHero-5*acceleration<875 and xHero-5*acceleration>859) or
                (positionGrafic==8 and yHero>125 and yHero<675 and xHero-5*acceleration<475) or
                ((positionGrafic==3 or positionGrafic==4 or positionGrafic==5) and yHero>125 and yHero<625 and xHero-5*acceleration<675) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>RIGHT_X) or
                (yHero>900 and xHero+5*acceleration>525) or
                (positionGrafic==6 and yHero>675 and xHero+5*acceleration>125) or
                ((positionGrafic==6 or positionGrafic==7) and yHero>125 and yHero<625 and xHero+5*acceleration>125) or
                (positionGrafic==8 and yHero>125 and yHero<625 and xHero+5*acceleration>525) or
                ((positionGrafic==3 or positionGrafic==4 or positionGrafic==5) and yHero>325 and yHero<825 and xHero+5*acceleration>725 and xHero+5*acceleration<741) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<UP_Y) or
                ((positionGrafic==1 or positionGrafic==2) and xHero>=475 and xHero<875 and yHero-5*acceleration<825) or
                (positionGrafic==3 and xHero>=675 and xHero<=RIGHT_X and yHero-5*acceleration<275) or
                ((positionGrafic==5 or positionGrafic==6) and xHero>125 and xHero<675 and yHero-5*acceleration<625) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>DOWN_Y) or
                (xHero>525 and xHero<=RIGHT_X and yHero+5*acceleration>875) or
                (xHero>725 and xHero<875 and yHero+5*acceleration>325) or
                ((positionGrafic==5 or positionGrafic==6) and xHero>125 and xHero<=725 and yHero+5*acceleration>675) or
                ((positionGrafic==7 or positionGrafic==8) and xHero>125 and xHero<475 and yHero+5*acceleration>125) or
                (positionGrafic==8 and xHero>=475 and xHero<=525 and yHero+5*acceleration>475) or
                (positionGrafic==8 and xHero>525 and xHero<=RIGHT_X and yHero+5*acceleration>125) or
                (positionGrafic==8 and secretUpdate==false and yHero+5*acceleration>125) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                }
            }

            selectPositionGrafic(xHero, yHero, &positionGrafic);

            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);

            if (positionGrafic==0 or positionGrafic==3 or positionGrafic==4 or positionGrafic==5 or positionGrafic==6)
            {
                txLine(800, 750, 800, MAX_Y);
            }

            drawGraficPlace(400, 750, 600, MAX_Y, 1, 0, &positionGrafic);
            drawGraficPlace(400, 750, MAX_X, 950, 2, 0, &positionGrafic);
            drawGraficPlace(800, 200, MAX_X, 950, 3, 0, &positionGrafic);
            drawGraficPlace(600, 200, MAX_X, 400, 4, 0, &positionGrafic);
            drawGraficPlace(600, 200, 801, 750, 5, 0, &positionGrafic);
            drawGraficPlace(MIN_X, 550, 800, 750, 6, 0, &positionGrafic);
            drawGraficPlace(MIN_X, MIN_Y, 200, MAX_Y, 7, 0, &positionGrafic);
            drawGraficPlace(MIN_X, MIN_Y, MAX_X, 200, 8, 0, &positionGrafic);

            if (secretUpdate==true)
            {
                drawGraficPlace(400, MIN_Y, 600, 550, 9, 0, &positionGrafic);//9
            }

            drawGraficPlace(801, 400, MAX_X, 550, 1, 1, &positionGrafic);
            drawGraficPlace(800, 750, MAX_X, 950, 2, 1, &positionGrafic);
            drawGraficPlace(801, 200, MAX_X, 400, 3, 1, &positionGrafic);
            drawGraficPlace(600, 550, 800, 750, 4, 1, &positionGrafic);
            drawGraficPlace(MIN_X, 550, 200, 750, 5, 1, &positionGrafic);
            drawGraficPlace(MIN_X, MIN_Y, 200, 200, 6, 1, &positionGrafic);
            drawGraficPlace(400, MIN_Y, 600, 200, 7, 1, &positionGrafic);

            if (mechanicUpdate)
            {
                for (int i=0; i<QUANTITY_BRIDGES_IN_GRAFIC; ++i)
                {
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                    if (txMouseX()>bridgesInGrafic[i].xLeft and txMouseY()>bridgesInGrafic[i].yLeft and txMouseX()<bridgesInGrafic[i].xLeft+200 and txMouseY()<bridgesInGrafic[i].yLeft+200)
                    {
                        txSetFillColor(TX_WHITE);
                        txSetColor(TX_WHITE);
                        bridgesInGrafic[i].state = true;
                    }
                    else
                    {
                        bridgesInGrafic[i].state = false;
                    }

                    if ((positionGrafic==1 and (i==0 or i==1)) or
                    ((positionGrafic==4 or positionGrafic==5) and i==0))
                    {
                        txSetFillColor(TX_BLACK);
                        txSetColor(TX_BLACK);
                    }
                    txRectangle(bridgesInGrafic[i].xLeft+2, bridgesInGrafic[i].yLeft+2, bridgesInGrafic[i].xLeft+198, bridgesInGrafic[i].yLeft+198);

                    if (xHero+60>bridgesInGrafic[i].xLeft and yHero+60>bridgesInGrafic[i].yLeft and xHero-60<bridgesInGrafic[i].xLeft+200 and yHero-60<bridgesInGrafic[i].yLeft+200 and !bridgesInGrafic[i].state)
                    {
                        heroInPuddle = true;
                    }
                    if (xHero+60>bridgesInGrafic[i].xLeft and yHero+60>bridgesInGrafic[i].yLeft and xHero-60<bridgesInGrafic[i].xLeft+200 and yHero-60<bridgesInGrafic[i].yLeft+200 and bridgesInGrafic[i].state)
                    {
                        heroInPuddle = false;
                    }
                }
            }

            drawHeroWithoutGrafics(xHero, yHero, heroInPuddle);
            drawFog(xHero, yHero);

            if (positionGrafic==3)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txLine(800, 400, 800, MAX_Y);
            }

            if (secretInGraficPlace and secretUpdate and positionGrafic==8)
            {
                drawSecret(400, 350, &phaseSecret, &directionSecret);
                if (xHero+25>400 and yHero+25>350)
                {
                    drawFog(xHero, yHero);
                    secretInGraficPlace = false;
                    secrets = secrets+1;
                    drawGettingSecret(&phaseSecret);
                }
            }

            if (xHero>800 and yHero<200)
            {
                drawFog(xHero, yHero);
                graficUpdate = true;
                xHero = CENTER_X;
                yHero = 80;
                graficPlace = false;
                startPlace = true;
                updatesSequence[updatesOrder] = GRAFIC;
                updatesOrder = updatesOrder+1;
                directionHeroWithGrafic = DOWN;
                drawGettingUpdate(GRAFIC);

                if (updatesOrder!=4 and storyUpdate)
                {
                    drawDeveloperMonologue(&developerMonologueNumber);
                }
            }

            drawFog(xHero, yHero);
        }

        if (mechanicPlace)
        {
            if(!graficUpdate)
            {
                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(180, MIN_Y, 200, 800);
                txRectangle(800, 200, 820, MAX_Y);
            }
            else
            {
                drawBackgroundWithGrafic();
                drawPuddle(200, MIN_Y, 800, MAX_Y);
                drawWave(250, 500);
                drawWave(300, 300);
                drawWave(340, 830);
                drawWave(370, 210);
                drawWave(410, 400);
                drawWave(480, 580);
                drawWave(500, 720);
                drawWave(530, 430);
                drawWave(590, 220);
                drawWave(620, 690);
                drawWave(462, 320);
                drawWave(657, 680);
                drawWave(740, 950);
                drawWave(710, 460);
                drawWave(240, 240);
                drawWave(680, 260);
                drawWave(699, 560);
                drawWave(230, 30);
                drawWave(310, 60);
                drawWave(720, 50);
                drawWave(430, 870);
                drawWave(720, 890);

                for (int i=0; i<QUANTITY_ROCKS_IN_MECHANIC; ++i)
                {
                    drawRock(180, 40*i);
                    drawRock(800, 200+40*i);
                }

            }

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration>874 and xHero-5*acceleration<895 and yHero>125)or
                (xHero-5*acceleration<LEFT_X)or
                (xHero-5*acceleration>255 and xHero-5*acceleration<275 and yHero<725) or
                (xHero-5*acceleration>200 and xHero-5*acceleration<475 and yHero>125 and yHero<475) or
                (xHero-5*acceleration<675 and xHero-5*acceleration>400 and yHero>725) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>105 and xHero+5*acceleration<125 and yHero<875) or
                (xHero+5*acceleration>RIGHT_X) or
                (xHero+5*acceleration>725 and xHero+5*acceleration<745 and yHero>125) or
                (xHero+5*acceleration>325 and xHero+5*acceleration<525 and yHero>725) or
                (xHero+5*acceleration>525 and xHero+5*acceleration<725 and yHero>125 and yHero<475) or
                (secretUpdate==false and xHero+5*acceleration>525 and xHero+5*acceleration<600 and yHero>525 and yHero<800) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((xHero>105 and xHero<275 and yHero-5*acceleration<800) or
                (yHero-5*acceleration<UP_Y) or
                (xHero>106 and xHero<274 and yHero-5*acceleration<875) or
                (xHero<475 and xHero>274 and yHero-5*acceleration<475 and yHero-5*acceleration>274) or
                (xHero<726 and xHero>525 and yHero-5*acceleration<475 and yHero-5*acceleration>274) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>DOWN_Y) or
                (xHero>725 and xHero<895 and yHero+5*acceleration>125) or
                (xHero>325 and xHero<675 and yHero+5*acceleration>725) or
                (xHero>274 and xHero<475 and yHero+5*acceleration>125 and yHero+5*acceleration<325) or
                (xHero>525 and xHero<726 and yHero+5*acceleration>125 and yHero+5*acceleration<325) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            for (int i=0; i<LINE_Y; ++i)
            {
                for (int j=0; j<LINE_X; ++j)
                {
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                    if (txMouseX()>bridgesInMechanic[i][j].xLeft and txMouseY()>bridgesInMechanic[i][j].yLeft and txMouseX()<bridgesInMechanic[i][j].xLeft+200 and txMouseY()<bridgesInMechanic[i][j].yLeft+200)
                    {
                        txSetFillColor(TX_WHITE);
                        txSetColor(TX_WHITE);
                        if (graficUpdate)
                        {
                            drawBridge(bridgesInMechanic[i][j].xLeft, bridgesInMechanic[i][j].yLeft);
                        }
                        bridgesInMechanic[i][j].state = true;
                    }
                    else
                    {
                        bridgesInMechanic[i][j].state = false;
                    }

                    if ((i==0 and j==1) or
                    (i==2 and j==1) or
                    (i==3 and j==0) or
                    (i==3 and j==2 and secretUpdate))
                    {
                        txSetFillColor(TX_WHITE);
                        txSetColor(TX_WHITE);
                        if (graficUpdate)
                        {
                            drawBridge(bridgesInMechanic[i][j].xLeft, bridgesInMechanic[i][j].yLeft);
                        }
                        bridgesInMechanic[i][j].state = true;
                    }
                    else
                    {
                        if (xHero+60>bridgesInMechanic[i][j].xLeft and yHero+60>bridgesInMechanic[i][j].yLeft and xHero-60<bridgesInMechanic[i][j].xLeft+200 and yHero-60<bridgesInMechanic[i][j].yLeft+200 and !bridgesInMechanic[i][j].state)
                        {
                            heroInPuddle = true;
                        }
                        if (xHero+60>bridgesInMechanic[i][j].xLeft and yHero+60>bridgesInMechanic[i][j].yLeft and xHero-60<bridgesInMechanic[i][j].xLeft+200 and yHero-60<bridgesInMechanic[i][j].yLeft+200 and bridgesInMechanic[i][j].state)
                        {
                            heroInPuddle = false;
                        }
                    }
                    if (!graficUpdate)
                    {
                        txRectangle(bridgesInMechanic[i][j].xLeft+2, bridgesInMechanic[i][j].yLeft+2, bridgesInMechanic[i][j].xLeft+198, bridgesInMechanic[i][j].yLeft+198);
                    }
                }
            }

            if (!graficUpdate)
            {
                drawHeroWithoutGrafics (xHero, yHero, heroInPuddle);
            }
            else
            {
                drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);
            }

            if (secretInMechanicPlace and secretUpdate and bridgesInMechanic[4][2].state)
            {
                drawSecret(600, 800, &phaseSecret, &directionSecret);
                if (xHero+25>600 and yHero+25>800 and xHero-25<800 and yHero-25<MAX_Y)
                {
                    secretInMechanicPlace = false;
                    secrets = secrets+1;
                    drawGettingSecret(&phaseSecret);
                }
            }

            if (xHero>895 and yHero>875)
            {
                mechanicUpdate = true;
                xHero = 925;
                yHero = CENTER_Y;
                mechanicPlace = false;
                startPlace = true;
                updatesSequence[updatesOrder] = MECHANIC;
                updatesOrder = updatesOrder+1;
                drawGettingUpdate (MECHANIC);

                if (updatesOrder!=4 and storyUpdate)
                {
                    drawDeveloperMonologue(&developerMonologueNumber);
                }
            }
        }

        if (secretPlace)
        {
            if (!graficUpdate)
            {
                drawSecretPlaceWithoutGrafics(levelInSecret);
            }
            else
            {
                drawSecretPlaceWithGrafics(levelInSecret, mechanicUpdate);
            }

            if (levelInSecret==1 or levelInSecret==2 or levelInSecret==3)
            {
                secretSituation = 1;
            }
            if (levelInSecret==4)
            {
                secretSituation = 2;
            }
            if (levelInSecret==5)
            {
                secretSituation = 3;
            }
            if (levelInSecret==6)
            {
                secretSituation = 4;
            }

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((secretSituation==1 and xHero-5*acceleration<575 and yHero>225 and yHero<775) or
                (levelInSecret==5 and xHero-5*acceleration<275) or
                (levelInSecret==6 and xHero-5*acceleration<275) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((secretSituation==1 and xHero+5*acceleration>625 and ((yHero>174 and yHero<475) or (yHero>525 and yHero<826))) or
                (levelInSecret==1 and xHero+5*acceleration>RIGHT_X) or
                (levelInSecret==5 and xHero+5*acceleration>425 and yHero>325 and yHero<675) or
                (levelInSecret==6 and xHero+5*acceleration>725 and (yHero<475 or yHero>525)) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((secretSituation==1 and yHero-5*acceleration<175 and xHero<626) or
                (secretSituation==1 and yHero-5*acceleration<775 and yHero-5*acceleration>700 and xHero<575) or
                (secretSituation==1 and yHero-5*acceleration<475 and xHero>625) or
                (levelInSecret==4 and yHero-5*acceleration<475) or
                (levelInSecret==5 and yHero-5*acceleration<275) or
                (levelInSecret==5 and yHero-5*acceleration<675 and yHero-5*acceleration>500 and xHero>425) or
                (levelInSecret==6 and yHero-5*acceleration<275) or
                (levelInSecret==6 and yHero-5*acceleration<475 and xHero>725) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((secretSituation==1 and yHero+5*acceleration>225 and yHero+5*acceleration<300 and xHero<575) or
                (secretSituation==1 and yHero+5*acceleration>825 and xHero<626) or
                (secretSituation==1 and yHero+5*acceleration>525 and xHero>625) or
                (levelInSecret==4 and yHero+5*acceleration>525) or
                (levelInSecret==5 and yHero+5*acceleration>725) or
                (levelInSecret==5 and yHero+5*acceleration>325 and yHero+5*acceleration<500 and xHero>425) or
                (levelInSecret==6 and yHero+5*acceleration>725) or
                (levelInSecret==6 and yHero+5*acceleration>525 and xHero>725) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if (levelInSecret==1 and xHero<0 and yHero>174 and yHero<226)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 2;
                xHero = 925;
                yHero = CENTER_Y;
            }
            if (levelInSecret==1 and xHero<0 and yHero>774 and yHero<826)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 3;
                xHero = 925;
                yHero = CENTER_Y;
            }
            if (levelInSecret==2 and xHero>MAX_X)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 1;
                xHero = 75;
                yHero = 200;
            }
            if (levelInSecret==2 and xHero<MIN_X and yHero<226)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 4;
                xHero = 925;
                yHero = CENTER_Y;
            }
            if (levelInSecret==2 and xHero<MIN_X and yHero>774)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 5;
                xHero = 925;
                yHero = 300;
            }
            if (levelInSecret==3 and xHero>MAX_X)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 1;
                xHero = 75;
                yHero = 800;
            }
            if (levelInSecret==3 and xHero<MIN_X and yHero<226)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 5;
                xHero = 925;
                yHero = 700;
            }
            if (levelInSecret==3 and xHero<MIN_X and yHero>774)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 6;
                xHero = 925;
                yHero = CENTER_Y;
            }
            if (levelInSecret==4 and xHero>MAX_X)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 2;
                xHero = 75;
                yHero = 200;
            }
            if (levelInSecret==5 and xHero>MAX_X and yHero<326)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 2;
                xHero = 75;
                yHero = 800;
            }
            if (levelInSecret==5 and xHero>MAX_X and yHero>674)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 3;
                xHero = 75;
                yHero = 200;
            }
            if (levelInSecret==6 and xHero>MAX_X)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSleep(1000);
                levelInSecret = 3;
                xHero = 75;
                yHero = 800;
            }

            if (!graficUpdate)
            {
                drawHeroWithoutGrafics (xHero, yHero, heroInPuddle);
            }
            else
            {
                drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);
            }

            if (mechanicUpdate)
            {
                for (int i=0; i<QUANTITY_BRIDGES_IN_SECRET; ++i)
                {
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                    if (txMouseX()>bridgesInSecret[i].xLeft and txMouseY()>bridgesInSecret[i].yLeft and txMouseX()<bridgesInSecret[i].xLeft+200 and txMouseY()<bridgesInSecret[i].yLeft+200)
                    {
                        if ((secretSituation==1 and i==0) or
                        (levelInSecret==4 and i==1) or
                        (levelInSecret==5 and i==2))
                        {
                            if (graficUpdate)
                            {
                                drawBridge(bridgesInSecret[i].xLeft, bridgesInSecret[i].yLeft);
                            }
                            else
                            {
                                txSetFillColor(TX_WHITE);
                                txSetColor(TX_WHITE);
                            }
                        }
                        bridgesInSecret[i].state = true;
                    }
                    else
                    {
                        bridgesInSecret[i].state = false;
                    }
                    if (!graficUpdate)
                    {
                        if ((secretSituation==1 and i==0) or
                        (levelInSecret==4 and i==1) or
                        (levelInSecret==5 and i==2))
                        {
                            txRectangle(bridgesInSecret[i].xLeft+2, bridgesInSecret[i].yLeft+2, bridgesInSecret[i].xLeft+198, bridgesInSecret[i].yLeft+198);
                        }
                    }
                    if ((xHero+60>bridgesInSecret[i].xLeft and yHero+60>bridgesInSecret[i].yLeft and xHero-60<bridgesInSecret[i].xLeft+200 and yHero-60<bridgesInSecret[i].yLeft+200 and !bridgesInSecret[i].state) and ((secretSituation==1 and i==0) or
                    (levelInSecret==4 and i==1) or
                    (levelInSecret==5 and i==2)))
                    {
                        heroInPuddle = true;
                    }
                    if ((xHero+60>bridgesInSecret[i].xLeft and yHero+60>bridgesInSecret[i].yLeft and xHero-60<bridgesInSecret[i].xLeft+200 and yHero-60<bridgesInSecret[i].yLeft+200 and bridgesInSecret[i].state) and ((secretSituation==1 and i==0) or
                    (levelInSecret==4 and i==1) or
                    (levelInSecret==5 and i==2)))
                    {
                        heroInPuddle = false;
                    }
                }
            }

            if (secretInSecretPlace and levelInSecret==6)
            {
                drawSecret(400, 400, &phaseSecret, &directionSecret);
                if (xHero+25>400 and yHero+25>400 and xHero-25<600 and yHero-25<600)
                {
                    secretInSecretPlace = false;
                    secrets = secrets+1;
                    drawGettingSecret(&phaseSecret);
                }
            }

            if (levelInSecret==4 and xHero<400)
            {
                secretUpdate = true;
                xHero = 75;
                yHero = CENTER_Y;
                secretPlace = false;
                startPlace = true;
                updatesSequence[updatesOrder] = SECRETS;
                updatesOrder = updatesOrder+1;
                drawGettingUpdate (SECRETS);

                if (updatesOrder!=4 and storyUpdate)
                {
                    drawDeveloperMonologue(&developerMonologueNumber);
                }
            }
        }

        if (storyPlace)
        {
            if(!graficUpdate)
            {
                drawStoryPlaceWithoutGrafics();
            }
            else
            {
                drawStoryPlaceWithGrafics(mechanicUpdate);
            }

            if (mechanicUpdate)
            {
                for (int i=0; i<QUANTITY_BRIDGES_IN_STORY; ++i)
                {
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                    if (txMouseX()>bridgesInStory[i].xLeft and txMouseY()>bridgesInStory[i].yLeft and txMouseX()<bridgesInStory[i].xLeft+200 and txMouseY()<bridgesInStory[i].yLeft+200)
                    {
                        if (!graficUpdate)
                        {
                            txSetFillColor(TX_WHITE);
                            txSetColor(TX_WHITE);
                        }
                        else
                        {
                            drawBridge(bridgesInStory[i].xLeft, bridgesInStory[i].yLeft);
                        }
                        bridgesInStory[i].state = true;
                    }
                    else
                    {
                        bridgesInStory[i].state = false;
                    }

                    if (!graficUpdate)
                    {
                        txRectangle(bridgesInStory[i].xLeft+2, bridgesInStory[i].yLeft+2, bridgesInStory[i].xLeft+198, bridgesInStory[i].yLeft+198);
                    }

                    if (xHero+60>bridgesInStory[i].xLeft and yHero+60>bridgesInStory[i].yLeft and xHero-60<bridgesInStory[i].xLeft+200 and yHero-60<bridgesInStory[i].yLeft+200 and !bridgesInStory[i].state)
                    {
                        heroInPuddle = true;
                    }
                    if (xHero+60>bridgesInStory[i].xLeft and yHero+60>bridgesInStory[i].yLeft and xHero-60<bridgesInStory[i].xLeft+200 and yHero-60<bridgesInStory[i].yLeft+200 and bridgesInStory[i].state)
                    {
                        heroInPuddle = false;
                    }
                }
            }

            pressShift(&acceleration);

            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<LEFT_X) or
                (xHero-5*acceleration<475 and xHero-5*acceleration>400 and yHero>74 and yHero<326) or
                (xHero-5*acceleration<875 and xHero-5*acceleration>800 and yHero>74 and yHero<426) or
                (xHero-5*acceleration<625 and xHero-5*acceleration>600 and yHero>874 and yHero<MAX_Y) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>RIGHT_X) or
                (xHero+5*acceleration>125 and xHero+5*acceleration<150 and yHero>74 and yHero<326) or
                (xHero+5*acceleration>525 and xHero+5*acceleration<550 and yHero>74 and yHero<326) or
                (xHero+5*acceleration>375 and xHero+5*acceleration<400 and yHero>874 and yHero<MAX_Y) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<UP_Y) or
                (yHero-5*acceleration<625 and yHero-5*acceleration>600 and xHero>MIN_X and xHero<MAX_X) or
                (yHero-5*acceleration<875 and yHero-5*acceleration>850 and xHero>MIN_X and xHero<476) or
                (yHero-5*acceleration<875 and yHero-5*acceleration>850 and xHero>624 and xHero<MAX_X) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>DOWN_Y) or
                (yHero+5*acceleration>325 and yHero+5*acceleration<350 and xHero>74 and xHero<126) or
                (yHero+5*acceleration>325 and yHero+5*acceleration<350 and xHero>474 and xHero<526) or
                (yHero+5*acceleration>425 and yHero+5*acceleration<450 and xHero>874 and xHero<MAX_X) or
                (yHero+5*acceleration>675 and yHero+5*acceleration<700 and xHero>MIN_X and xHero<MAX_X) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if (xHero<126 and yHero<256)//1
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 1);
            }
            else if (xHero>874 and yHero<256)//2
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 2);
            }
            else if (xHero>474 and yHero>144 and xHero<526 and yHero<326)//3
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 3);
            }
            else if (xHero>874 and yHero>244 and yHero<426)//4
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 4);
            }
            else if (xHero<256 and yHero>624 and yHero<676)//5
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 5);
            }
            else if (xHero>344 and xHero<656 and yHero>624 and yHero<676)//6
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 6);
            }
            else if (xHero>744 and yHero>624 and yHero<676)//7
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 7);
            }
            else if (xHero>294 and xHero<476 and yHero>874)//8
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 8);
            }
            else if (xHero>624 and xHero<806 and yHero>874)//9
            {
                selectionPortalInStory(&xHero, &yHero, heroInPuddle, 9);
            }

            if (!graficUpdate)
            {
                drawHeroWithoutGrafics (xHero, yHero, heroInPuddle);
            }
            else
            {
                drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);
            }

            if (secretInStoryPlace and secretUpdate)
            {
                drawSecret(MIN_X, 800, &phaseSecret, &directionSecret);
                if (xHero+25>MIN_X and yHero+25>800 and xHero-25<200 and yHero-25<MAX_Y)
                {
                    secretInStoryPlace = false;
                    secrets = secrets+1;
                    drawGettingSecret(&phaseSecret);
                }
            }

            if (xHero>800 and yHero>800)
            {
                storyUpdate = true;
                xHero = CENTER_X;
                yHero = 925;
                storyPlace = false;
                startPlace = true;
                updatesSequence[updatesOrder] = STORY;
                updatesOrder = updatesOrder+1;
                drawGettingUpdate (STORY);

                if (updatesOrder!=4)
                {
                    drawDeveloperMonologue(&developerMonologueNumber);
                }
            }
        }

        if (updatesOrder==4)
        {
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
            txSleep(500);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
            for (int i=1; i<QUANTITY_RECTANGLES_IN_LOADING; ++i)
            {
                txRectangle(MIN_X, MIN_Y, MAX_X, 20*i);
                txRectangle(MIN_X, MIN_Y, 20*i, MAX_Y);
                txRectangle(MIN_X, MAX_Y, MAX_X, MAX_Y-20*i);
                txRectangle(MAX_X, MIN_Y, MAX_X-20*i, MAX_Y);
                txSleep(10);
            }
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            for (int i=1; i<QUANTITY_RECTANGLES_IN_LOADING; ++i)
            {
                txRectangle(500-20*i, 500-20*i, 500+20*i, 500+20*i);
                txSleep(10);
            }
            drawLoading(LOADINGS, 200, 100, 500, 200, 100,
            410, 415, 450, 460, 570);

            for (int i=0; i<updatesOrder; ++i)
            {
                if (updatesSequence[i]==GRAFIC)
                {
                    drawLoading(GRAFIC, 100, 200, 300, 200, 200,
                    450, 468, 501, 580, 590);
                }

                if (updatesSequence[i]==MECHANIC)
                {
                    drawLoading(MECHANIC, 400, 100, 150, 200, 150,
                    430, 510, 524, 560, 580);
                }

                if (updatesSequence[i]==SECRETS)
                {
                    drawLoading(SECRETS, 100, 200, 50, 350, 300,
                    410, 430, 470, 520, 570);
                }

                if (updatesSequence[i]==STORY)
                {
                    drawLoading(STORY, 700, 100, 50, 50, 100,
                    500, 525, 535, 550, 555);
                }
            }
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
            txSelectFont("Comic Sans MS", 120, 50, 1000);
            for (int i=0; i<ADVENTURE; ++i)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);
                txDrawText(MIN_X, -200+10*i, MAX_X, 200+10*i, "œ–» Àﬁ◊≈Õ»≈\n¡Œ¡¡»"); //300, 700
                txSleep(20);
            }
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
            txSelectFont("Comic Sans MS", 30, 10);
            txTextOut(375, 540, "¿Î¸Ù‡-ÚÂÒÚËÓ‚‡ÌËÂ 1.0");
            txSleep(1500);
            for (int i=0; i<ALPHA; ++i)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);
                txSelectFont("Comic Sans MS", 30, 10);
                txTextOut(375+3.5*i, 540+4*i, "¿Î¸Ù‡-ÚÂÒÚËÓ‚‡ÌËÂ 1.0");
                txSelectFont("Comic Sans MS", 120, 50, 1000);
                txDrawText(MIN_X-8*i, 300, MAX_X-8*i, 700, "œ–» Àﬁ◊≈Õ»≈\n¡Œ¡¡»");
                txSleep(5);
            }

            startPlace = false;
            beginningInTheGame = true;
            updatesOrder = 5;
            xHero = CENTER_X;
            yHero = CENTER_Y;
            directionHeroWithGrafic = RIGHT;
        }

        if (beginningInTheGame)
        {
            drawBeginningInTheGame();

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if(xHero-5*acceleration<275)
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if(xHero+5*acceleration>725 and ((yHero>274 and yHero<475) or (yHero>525 and yHero<726)))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<275) or
                   (yHero-5*acceleration<475 and xHero>725))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>725) or
                   (yHero+5*acceleration>525 and xHero>725))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (returnInStart)
            {
                drawGameDialog(HERO_RETURN_TO_THE_FIRST_LOCATION, &firstBugInGame, &normalGame);
                returnInStart = false;
            }

            if (xHero>MAX_X)
            {
                xHero = 75;
                yHero = CENTER_Y;
                beginningInTheGame = false;
                forkInTheGame = true;
                returnInStart = true;
            }

            if (firstGameStart)
            {
                drawGameDialog(THE_APPEARANCE_OF_HERO, &firstBugInGame, &normalGame);
                firstGameStart = false;
            }
        }

        if (forkInTheGame)
        {
            drawForkInTheGame(destroyRock);

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<275 and ((yHero>274 and yHero<475) or (yHero>525 and yHero<726))) or
                (xHero-5*acceleration<475 and ((yHero>MIN_Y and yHero<275) or (yHero>725 and yHero<MAX_Y))))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if(xHero+5*acceleration>725 and ((yHero>274 and yHero<475) or (yHero>525 and yHero<726)) or
                (xHero+5*acceleration>525 and ((yHero>MIN_Y and yHero<275) or (yHero>725 and yHero<MAX_Y))))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<275 and ((xHero>274 and xHero<475) or (xHero>525 and xHero<726))) or
                (yHero-5*acceleration<475 and ((xHero>MIN_X and xHero<275) or (xHero>725 and xHero<MAX_X))) or
                (!destroyRock and yHero-5*acceleration<275))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if(yHero+5*acceleration>725 and ((xHero>274 and xHero<475) or (xHero>525 and xHero<726)) or
                (yHero+5*acceleration>525 and ((xHero>MIN_X and xHero<275) or (xHero>725 and xHero<MAX_X))))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if (xHero<MIN_X)
            {
                xHero = 925;
                yHero = CENTER_Y;
                forkInTheGame = false;
                beginningInTheGame = true;
            }

            if (yHero>MAX_Y)
            {
                xHero = 200;
                yHero = 75;
                forkInTheGame = false;
                townInTheGame = true;
            }

            if (xHero>MAX_X)
            {
                xHero = 75;
                yHero = CENTER_Y;
                forkInTheGame = false;
                firstRiverInTheGame = true;
            }

            if (yHero<MIN_Y)
            {
                yHero = 925;
                forkInTheGame = false;
                secretPlaceInTheGame = true;
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (xHero>450 and xHero<550 and yHero==275 and !pickaxe and stayNearStone)
            {
                if (firstStoneWithoutPickaxe)
                {
                    drawGameDialog(HERO_FIRST_SEES_A_STONE_WITHOUT_A_PICKAXE, &firstBugInGame, &normalGame);
                    firstStoneWithoutPickaxe = false;
                }
                else
                {
                    drawGameDialog(HERO_SEES_A_STONE_WITHOUT_A_PICKAXE, &firstBugInGame, &normalGame);
                }

                stayNearStone = false;
            }

            if (!(xHero>450 and xHero<550 and yHero==275 and !pickaxe))
            {
                stayNearStone = true;
            }

            if (xHero>450 and xHero<550 and yHero==275 and pickaxe and !destroyRock)
            {
                drawGameDialog(HERO_DESTROY_STONE, &firstBugInGame, &normalGame);
                destroyRock = true;
            }

            if (firstGameFork)
            {
                drawGameDialog(HERO_FIRST_COMES_TO_THE_FORK, &firstBugInGame, &normalGame);
                firstGameFork = false;
            }
        }

        if (secretPlaceInTheGame)
        {
            drawSecretPlaceInTheGame();

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<475 and yHero>725) or
                (xHero-5*acceleration<175 and yHero>674))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>525 and yHero>725) or
                (xHero+5*acceleration>825 and yHero>674))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if(yHero-5*acceleration<675 and yHero-5*acceleration>650 and xHero>176)
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if(yHero+5*acceleration>725 and (xHero<475 or xHero>525))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (secretInSecretPlaceInTheGame)
            {
                drawSecret(800, 70, &phaseSecret, &directionSecret);

                //drawSecret(400, 400, &phaseSecret, &directionSecret);

                if (xHero+25>800 and yHero+25>70 and xHero-25<MAX_X and yHero-25<270)
                {
                    secretInSecretPlaceInTheGame = false;
                    bridgeInGame = bridgeInGame+1;
                    drawGettingSecret(&phaseSecret);

                    drawGameDialog(HERO_FIND_SECRET_BRIDGE, &firstBugInGame, &normalGame);
                }
            }

            if (firstComesInSecretPlaceInGame)
            {
                drawGameDialog(HERO_FIRST_COMES_IN_SECRET_PLACE, &firstBugInGame, &normalGame);
                firstComesInSecretPlaceInGame = false;
            }

            if (yHero<675 and heroWentTroughFence)
            {
                drawGameDialog(HERO_WENT_TROUGH_FENCE, &firstBugInGame, &normalGame);
                heroWentTroughFence = false;
            }

            if (yHero>MAX_X)
            {
                xHero = CENTER_X;
                yHero = 75;
                secretPlaceInTheGame = false;
                forkInTheGame = true;
            }
        }

        if (firstRiverInTheGame)
        {
            drawFirstRiverInTheGame();

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if(heroInPuddle)
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>325 and bridgeInGame==0) or
                (xHero+5*acceleration>525 and bridgeInGame==1) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<475) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>525) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            for (int i=0; i<QUANTITY_BRIDGES_IN_FIRST_RIVER; ++i)
            {
                if (txMouseX()>bridgesInFirstRiverInTheGame[i].xLeft and txMouseY()>bridgesInFirstRiverInTheGame[i].yLeft and txMouseX()<bridgesInFirstRiverInTheGame[i].xLeft+200 and txMouseY()<bridgesInFirstRiverInTheGame[i].yLeft+200)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }
                else
                {
                    bridgesInFirstRiverInTheGame[i].state = false;
                }

                if (bridgeInGame>0 and i==0)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }

                if (bridgeInGame>1 and i==1)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }

                if (xHero+60>bridgesInFirstRiverInTheGame[i].xLeft and yHero+60>bridgesInFirstRiverInTheGame[i].yLeft and xHero-60<bridgesInFirstRiverInTheGame[i].xLeft+200 and yHero-60<bridgesInFirstRiverInTheGame[i].yLeft+200 and !bridgesInFirstRiverInTheGame[i].state)
                {
                    heroInPuddle = true;
                }
                if (xHero+60>bridgesInFirstRiverInTheGame[i].xLeft and yHero+60>bridgesInFirstRiverInTheGame[i].yLeft and xHero-60<bridgesInFirstRiverInTheGame[i].xLeft+200 and yHero-60<bridgesInFirstRiverInTheGame[i].yLeft+200 and bridgesInFirstRiverInTheGame[i].state)
                {
                    heroInPuddle = false;
                }
            }

            if (xHero<MIN_X)
            {
                xHero = 925;
                yHero = CENTER_Y;
                firstRiverInTheGame = false;
                forkInTheGame = true;
            }

            if (xHero>MAX_X)
            {
                xHero = 75;
                yHero = CENTER_Y;
                firstRiverInTheGame = false;
                secondRiverInTheGame = true;
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (firstGameRiver and firstMeetingWithCarpenter)
            {
                drawGameDialog(HERO_FIRST_COMES_TO_THE_RIVER_WITHOUT_BRIDGES, &firstBugInGame, &normalGame);
                firstGameRiver = false;
            }

            if (!firstMeetingWithCarpenter and firstSeeNewBridge)
            {
                drawGameDialog(HERO_FIRST_SEE_NEW_BRIDGE, &firstBugInGame, &normalGame);//
                firstSeeNewBridge = false;
            }
        }

        if (secondRiverInTheGame)
        {
            drawSecondRiverInTheGame(secrets);

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<475 and yHero<475) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>525 and yHero<475) or
                (xHero+5*acceleration>325 and bridgeInGame==2) or
                (xHero+5*acceleration>525 and bridgeInGame==3) or
                (xHero+5*acceleration>725 and bridgeInGame==4) or
                (heroInPuddle))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<475 and (xHero<475 or xHero>525)) or
                (yHero-5*acceleration<175 and xHero>475 and xHero<525 and secrets==3) or
                (yHero-5*acceleration<225 and xHero>475 and xHero<525 and secrets==4) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>525) or
                (heroInPuddle))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            for (int i=0; i<QUANTITY_BRIDGES_IN_SECOND_RIVER; ++i)
            {
                if (txMouseX()>bridgesInFirstRiverInTheGame[i].xLeft and txMouseY()>bridgesInFirstRiverInTheGame[i].yLeft and txMouseX()<bridgesInFirstRiverInTheGame[i].xLeft+200 and txMouseY()<bridgesInFirstRiverInTheGame[i].yLeft+200)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }
                else
                {
                    bridgesInFirstRiverInTheGame[i].state = false;
                }

                if (bridgeInGame>2 and i==0)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }

                if (bridgeInGame>3 and i==1)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;
                }

                if (bridgeInGame>4 and i==2)
                {
                    drawBridge(bridgesInFirstRiverInTheGame[i].xLeft, bridgesInFirstRiverInTheGame[i].yLeft);
                    bridgesInFirstRiverInTheGame[i].state = true;

                    txSetFillColor(TX_WHITE);
                    txSetColor(TX_BLACK);
                    txRectangle(600, 400, 800, 600);
                    txSelectFont("Arial", 90, 25);
                    txDrawText(575, 400, 825, 600, "?");
                }

                if (xHero+60>bridgesInFirstRiverInTheGame[i].xLeft and yHero+60>bridgesInFirstRiverInTheGame[i].yLeft and xHero-60<bridgesInFirstRiverInTheGame[i].xLeft+200 and yHero-60<bridgesInFirstRiverInTheGame[i].yLeft+200 and !bridgesInFirstRiverInTheGame[i].state)
                {
                    heroInPuddle = true;
                }
                if (xHero+60>bridgesInFirstRiverInTheGame[i].xLeft and yHero+60>bridgesInFirstRiverInTheGame[i].yLeft and xHero-60<bridgesInFirstRiverInTheGame[i].xLeft+200 and yHero-60<bridgesInFirstRiverInTheGame[i].yLeft+200 and bridgesInFirstRiverInTheGame[i].state)
                {
                    heroInPuddle = false;
                }
            }

            if (xHero<MIN_X)
            {
                xHero = 925;
                yHero = CENTER_Y;
                secondRiverInTheGame = false;
                firstRiverInTheGame = true;
            }

            if (xHero>MAX_X)
            {
                xHero = 75;
                yHero = CENTER_Y;
                secondRiverInTheGame = false;
                theEndPlace = true;
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (secondRiverGame)
            {
                drawGameDialog(HERO_FIRST_COMES_TO_SECOND_RIVER, &firstBugInGame, &normalGame);
                secondRiverGame = false;
            }

            if (heroFirstSeeSecretBridge and bridgeInGame==5)
            {
                drawGameDialog(HERO_FIRST_SEE_SECRET_BRIDGE, &firstBugInGame, &normalGame);
                heroFirstSeeSecretBridge = false;
            }

            if (yHero<230)
            {
                if (firstStayInEmptyLootPlace and secrets==3)
                {
                    drawGameDialog(HERO_IN_EMPTY_LOOT_PLACE, &firstBugInGame, &normalGame);
                    firstStayInEmptyLootPlace = false;
                }

                if (firstStayInLootPlaceWithChest and secrets==4 and !doingQuestFromMiner)
                {
                    drawGameDialog(HERO_IN_LOOT_PLACE_WITH_CHEST_WITHOUT_QUEST, &firstBugInGame, &normalGame);
                    firstStayInLootPlaceWithChest = false;
                }

                if (meetingWithChestWithQuest and secrets==4 and doingQuestFromMiner)
                {
                    drawGameDialog(HERO_IN_LOOT_PLACE_WITH_CHEST_WITH_QUEST, &firstBugInGame, &normalGame);
                    meetingWithChestWithQuest = false;
                    doingQuestFromMiner = false;
                    firstStayInLootPlaceWithChest = false;
                    completeQuestFromMiner = true;
                }
            }
        }

        if (theEndPlace)
        {
            drawTheEndPlace();

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            drawGameDialog(HERO_MEET_THE_END, &firstBugInGame, &normalGame);

            for (int i=0; i<110; i++)
            {
                txSetColor(TX_BLACK);
                txSetFillColor(TX_WHITE);
                txRectangle(250-3*i, 400-4*i, 750+3*i, 600+4*i);

                txSelectFont("Arial", 150+2*i);
                txDrawText(250-3*i, 400-4*i, 750+3*i, 600+4*i, " ŒÕ≈÷");
                txSleep(10);
            }

            drawEpilogue(CREATION);
        }

        if (townInTheGame)
        {
            drawTownInTheGame(secrets, updatesSequence[0]);

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<175) or
                (secrets>=1 and xHero-5*acceleration<675 and xHero-5*acceleration>650 and yHero>174 and yHero<375) or
                (secrets>=3 and xHero-5*acceleration<475 and yHero>625) or
                (secrets>=4 and xHero-5*acceleration<775 and yHero>625))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>825 and yHero<775) or
                (xHero+5*acceleration>225 and yHero<175) or
                (secrets>=1 and xHero+5*acceleration>225 and xHero+5*acceleration<250 and yHero>25 and yHero<375))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<175 and xHero>225) or
                (yHero-5*acceleration<775 and xHero>825) or
                (secrets>=1 and yHero-5*acceleration<375 and xHero>225 and xHero<625) or
                (secrets>=2 and yHero-5*acceleration<375 and xHero>225))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if((yHero+5*acceleration>825) or
                (secrets>=3 and yHero+5*acceleration>625 and xHero<475) or
                (secrets>=4 and yHero+5*acceleration>625 and xHero<775))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if (yHero<MIN_Y)
            {
                xHero = CENTER_X;
                yHero = 925;
                townInTheGame = false;
                forkInTheGame = true;
            }

            if (xHero>MAX_X)
            {
                xHero = 75;
                yHero = 800;
                townInTheGame = false;
                placeOfGreed = true;
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (secrets==0 and firstGameTown)
            {
                drawGameDialog(HERO_FIRST_COMES_TO_AN_EMPTY_CITY, &firstBugInGame, &normalGame);
                firstGameTown = false;
            }

            if (secrets==1 and firstGameTown)
            {
                drawGameDialog(HERO_FIRST_COMES_IN_SITY_WITH_CARPENTER, &firstBugInGame, &normalGame);//
                firstGameTown = false;
            }

            if (secrets==2 and firstGameTown)
            {
                drawGameDialog(HERO_FIRST_COMES_IN_CITY_WITH_ERROR, &firstBugInGame, &normalGame);//
                firstGameTown = false;
            }

            if (secrets==3 and firstGameTown)
            {
                drawGameDialog(HERO_FIRST_COMES_IN_SITY_WITH_WORKER, &firstBugInGame, &normalGame);//
                firstGameTown = false;
            }

            if (secrets==4 and firstGameTown)
            {
                drawGameDialog(HERO_FIRST_COMES_IN_SITY_WITH_MINER, &firstBugInGame, &normalGame);//
                firstGameTown = false;
            }

            if (xHero>400 and xHero<500 and yHero<380 and stayNearCarpenter and secrets>0)
            {
                if (!firstMeetingWithCarpenter)
                {
                    drawGameDialog(HERO_TALK_WITH_CARPENTER, &firstBugInGame, &normalGame);//
                }

                if (!firstStoneWithoutPickaxe and firstTalkWithCarpenterAboutStone and !firstMeetingWithCarpenter and !destroyRock)
                {
                    drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_STONE, &firstBugInGame, &normalGame);//
                    firstTalkWithCarpenterAboutStone = false;
                }

                if (!firstMeetingWithError and firstTalkWithCarpenterAboutError and !firstMeetingWithCarpenter)
                {
                    drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_ERROR, &firstBugInGame, &normalGame);//
                    firstTalkWithCarpenterAboutError = false;
                    bridgeInGame += 1;
                }

                if (!firstMeetingWithWorker and firstTalkWithCarpenterAboutWorker and !firstMeetingWithCarpenter)
                {
                    if (updatesSequence[0]==GRAFIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_ARCHITECT, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==MECHANIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_ENGINEER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==SECRETS)
                    {
                       drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_QUESTIONNAIRE, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==STORY)
                    {
                       drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_LIBRARIAN, &firstBugInGame, &normalGame);
                    }

                    firstTalkWithCarpenterAboutWorker = false;
                    bridgeInGame += 1;
                }

                if (firstTalkWithCarpenterAboutMiner and !firstMeetingWithMiner and !firstMeetingWithCarpenter)
                {
                    drawGameDialog(HERO_TALK_WITH_CARPENTER_ABOUT_MINER, &firstBugInGame, &normalGame);//
                    firstTalkWithCarpenterAboutMiner = false;
                    bridgeInGame += 1;
                }


                if (firstMeetingWithCarpenter)
                {
                    drawGameDialog(HERO_FIRST_TALK_WITH_CARPENTER, &firstBugInGame, &normalGame);//
                    firstMeetingWithCarpenter = false;
                    bridgeInGame += 1;
                }

                stayNearCarpenter = false;
            }

            if (xHero>700 and xHero<800 and yHero<380 and stayNearError and secrets>1)
            {
                if (firstMeetingWithError)
                {
                    drawGameDialog(HERO_FIRST_TALK_WITH_ERROR, &firstBugInGame, &normalGame);//
                    firstMeetingWithError = false;
                }
                else
                {
                    drawGameDialog(HERO_TALK_WITH_ERROR, &firstBugInGame, &normalGame);//
                }

                stayNearError = false;
            }

            if (xHero>200 and xHero<300 and yHero>620 and stayNearWorker and secrets>2)
            {
                if (!firstMeetingWithWorker)
                {
                    if (updatesSequence[0]==GRAFIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ARCHITECT, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==MECHANIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ENGINEER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==SECRETS)
                    {
                       drawGameDialog(HERO_TALK_WITH_QUESTIONNAIRE, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==STORY)
                    {
                       drawGameDialog(HERO_TALK_WITH_LIBRARIAN, &firstBugInGame, &normalGame);
                    }
                }


                if (!firstMeetingWithCarpenter and firstTalkWithWorkerAboutCarpenter and !firstMeetingWithWorker)
                {
                    if (updatesSequence[0]==GRAFIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ARCHITECT_ABOUT_CARPENTER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==MECHANIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ENGINEER_ABOUT_CARPENTER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==SECRETS)
                    {
                       drawGameDialog(HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_CARPENTER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==STORY)
                    {
                       drawGameDialog(HERO_TALK_WITH_LIBRARIAN_ABOUT_CARPENTER, &firstBugInGame, &normalGame);
                    }

                    firstTalkWithWorkerAboutCarpenter = false;
                }

                if (!firstMeetingWithError and firstTalkWithWorkerAboutError and !firstMeetingWithWorker)
                {
                    if (updatesSequence[0]==GRAFIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ARCHITECT_ABOUT_ERROR, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==MECHANIC)
                    {
                        drawGameDialog(HERO_TALK_WITH_ENGINEER_ABOUT_ERROR, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==SECRETS)
                    {
                       drawGameDialog(HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_ERROR, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==STORY)
                    {
                       drawGameDialog(HERO_TALK_WITH_LIBRARIAN_ABOUT_ERROR, &firstBugInGame, &normalGame);
                    }

                    firstTalkWithWorkerAboutError = false;
                }

                if (!firstTalkWithWorkerAboutMiner and !firstMeetingWithMiner and !firstMeetingWithWorker)
                {
                    drawGameDialog(HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_MINER, &firstBugInGame, &normalGame);
                    firstTalkWithWorkerAboutMiner = false;
                }


                if (firstMeetingWithWorker)
                {
                    if (updatesSequence[0]==GRAFIC)
                    {
                        drawGameDialog(HERO_FIRST_TALK_WITH_ARCHITECT, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==MECHANIC)
                    {
                        drawGameDialog(HERO_FIRST_TALK_WITH_ENGINEER, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==SECRETS)
                    {
                       drawGameDialog(HERO_FIRST_TALK_WITH_QUESTIONNAIRE, &firstBugInGame, &normalGame);
                    }

                    if (updatesSequence[0]==STORY)
                    {
                       drawGameDialog(HERO_FIRST_TALK_WITH_LIBRARIAN, &firstBugInGame, &normalGame);
                    }

                    firstMeetingWithWorker = false;
                }

                stayNearWorker = false;
            }

            if (xHero>500 and xHero<600 and yHero>620 and stayNearMiner and secrets>3)
            {
                if (!firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_TALK_WITH_MINER, &firstBugInGame, &normalGame);//
                }

                if (doingQuestFromMiner and !firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_TALK_WITH_MINER_ABOUT_QUEST, &firstBugInGame, &normalGame);//
                }

                if (completeQuestFromMiner and !pickaxe and !firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_GET_AWARD_FROM_MINER, &firstBugInGame, &normalGame);//
                    pickaxe = true;
                }

                if (!firstMeetingWithCarpenter and firstTalkWithMinerAboutCarpenter and !firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_TALK_WITH_MINER_ABOUT_CARPENTER, &firstBugInGame, &normalGame);//
                    firstTalkWithMinerAboutCarpenter = false;
                }

                if (!firstMeetingWithError and firstTalkWithMinerAboutError and !firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_TALK_WITH_MINER_ABOUT_ERROR, &firstBugInGame, &normalGame);//
                    firstTalkWithMinerAboutError = false;
                }

                if (!firstMeetingWithWorker and firstTalkWithMinerAboutWorker and !firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_TALK_WITH_MINER_ABOUT_QUESTIONNAIRE, &firstBugInGame, &normalGame);
                    firstTalkWithMinerAboutWorker = false;
                }


                if (firstMeetingWithMiner)
                {
                    drawGameDialog(HERO_FIRST_TALK_WITH_MINER, &firstBugInGame, &normalGame);//
                    firstMeetingWithMiner = false;
                    doingQuestFromMiner = true;
                }

                stayNearMiner = false;
            }


            if (!(xHero>400 and xHero<500 and yHero<380))
            {
                stayNearCarpenter = true;
            }

            if (!(xHero>700 and xHero<800 and yHero<380))
            {
                stayNearError = true;
            }

            if (!(xHero>200 and xHero<300 and yHero>620))
            {
                stayNearWorker = true;
            }

            if (!(xHero>500 and xHero<600 and yHero>620 ))
            {
                stayNearMiner = true;
            }
        }

        if (placeOfGreed)
        {
            drawPlaceOfGreed();

            pressShift(&acceleration);
            if (GetAsyncKeyState(0x41))
            {
                if((xHero-5*acceleration<375 and yHero>374 and yHero<775) or
                (xHero-5*acceleration<615 and xHero-5*acceleration>500 and yHero<475))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero-5*acceleration;
                    directionHeroWithGrafic = LEFT;
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                if((xHero+5*acceleration>625) or
                (xHero+5*acceleration>385 and xHero+5*acceleration<500 and yHero<475))
                {
                    xHero = xHero;
                }
                else
                {
                    xHero = xHero+5*acceleration;
                    directionHeroWithGrafic = RIGHT;
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                if((yHero-5*acceleration<375 and xHero>374) or
                (yHero-5*acceleration<775 and xHero<375) or
                (yHero-5*acceleration<475 and xHero>385 and xHero<615))
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-5*acceleration;
                    directionHeroWithGrafic = UP;
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                if(yHero+5*acceleration>825)
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+5*acceleration;
                    directionHeroWithGrafic = DOWN;
                }
            }

            if (xHero<MIN_X)
            {
                xHero = 925;
                yHero = 800;
                placeOfGreed = false;
                townInTheGame = true;
            }

            if (yHero>475)
            {
                thinkingAboutAdvertising = false;
            }

            drawHeroWithGrafics(xHero, yHero, heroInPuddle, directionHeroWithGrafic);

            if (firstPlaceOfGreed)
            {
                drawGameDialog(HERO_FIRST_COMES_TO_A_PLACE_OF_GREED, &firstBugInGame, &normalGame);
                firstPlaceOfGreed = false;
            }

            if (yHero<=475 and !thinkingAboutAdvertising)
            {
                if (firstMeetingWithAdvertistingContract)
                {
                    drawGameDialog(HERO_FIRST_READS_AN_ADVERTISING_CONTRACT, &firstBugInGame, &normalGame);
                    firstMeetingWithAdvertistingContract = false;
                }
                else
                {
                    drawGameDialog(HERO_READS_AN_ADVERTISING_CONTRACT, &firstBugInGame, &normalGame);
                }
                thinkingAboutAdvertising = true;
            }
        }

        txSleep(50);
        txSetFillColor(TX_WHITE);
        txClear();
    }

    txSetFillColor(TX_WHITE);
    txClear();
    txSleep(1000);

    for (int i = 0; i<INCREASE_IN_TEXT; ++i)
    {
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(100, 100, 900, 300);
        txSelectFont("Comic Sans MS", 10+1*i);
        selectColorInFakeMenu(&numberColorInFakeMenu);
        txDrawText(100, 100, 900, 300, "œËÍÎ˛˜ÂÌËÂ ¡Ó··Ë");
        txSleep(10);
    }

    for (int i=0; i<MOVEMENT_OT_SHADOW; ++i)
    {
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txRectangle(100, 100, 900, 300);
        txSetColor(TX_BLACK);
        txDrawText(100-0.2*i, 100+0.2*i, 900-0.2*i, 300+0.2*i, "œËÍÎ˛˜ÂÌËÂ ¡Ó··Ë");
        selectColorInFakeMenu(&numberColorInFakeMenu);
        txDrawText(100, 100, 900, 300, "œËÍÎ˛˜ÂÌËÂ ¡Ó··Ë");
        txSleep(10);
    }

    xHero = 200;
    yHero = SECOND_LINE+100;

    while(true)
    {
        if (fakeMenu)
        {
            txSelectFont("Comic Sans MS", 110);
            txSetColor(TX_BLACK);
            txDrawText(96, 104, 896, 304, "œËÍÎ˛˜ÂÌËÂ ¡Ó··Ë");
            selectColorInFakeMenu(&numberColorInFakeMenu);
            txDrawText(100, 100, 900, 300, "œËÍÎ˛˜ÂÌËÂ ¡Ó··Ë");

            txSetColor(TX_BLACK);
            txSetFillColor(TX_GREEN);

            if (txMouseX()>100 and txMouseY()>400 and txMouseX()<900 and  txMouseY()<800)
            {
                txSetFillColor(TX_WHITE);
            }

            txRectangle(100, 400, 900, 800);
            txSelectFont("Comic Sans MS", 400, 90);
            txDrawText(100, 400, 900, 800, "»√–¿“‹");

            if (!deleteFakeExit)
            {
                txSetFillColor(TX_RED);
                if (txMouseX()>400 and txMouseY()>850 and txMouseX()<600 and  txMouseY()<950)
                {
                    txSetFillColor(TX_WHITE);
                }

                txRectangle(400, 850, 600, 950);

                txSelectFont("Comic Sans MS", 80, 25);

                if (!fakeExit)
                {
                    txDrawText(400, 850, 600, 950, "‚˚ıÓ‰");
                }
                else
                {
                    txDrawText(400, 850, 600, 950, "ÌÂÚ");
                }

                if (txMouseX()>400 and txMouseY()>850 and txMouseX()<600 and  txMouseY()<950 and txMouseButtons()==1)
                {
                    if (fakeExit and txMouseButtons()==1)
                    {
                        deleteFakeExit = true;
                    }

                    fakeExit = true;
                }

                if (!(txMouseX()>400 and txMouseY()>850 and txMouseX()<600 and  txMouseY()<950))
                {
                    fakeExit = false;
                }
            }

            if (txMouseX()>100 and txMouseY()>400 and txMouseX()<900 and  txMouseY()<800 and txMouseButtons()==1)
            {
                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);

                for (int i=1; i<RECTANGLES_FOR_START_FAKE_GAME; ++i)
                {
                    txRectangle(MIN_X, MIN_Y, MAX_X, 100*i);
                    txSleep(100);
                }

                for (int i=0; i<RECTANGLES_FOR_START_FAKE_GAME-1; ++i)
                {
                    drawBackgroundInFakeGame(xForFakeGame);
                    txSetFillColor(TX_WHITE);
                    txSetColor(TX_WHITE);
                    txRectangle(MIN_X, MIN_Y, MAX_X, 900-100*i);
                    txSleep(100);
                }

                fakeMenu = false;
                fakeGame = true;

                drawGameDialog(DEVELOPER_TRAINS_PLAYER, &firstBugInGame, &normalGame);
            }
        }

        if (fakeGame)
        {
            stepInFakeGame = stepInFakeGame+1;

            drawBackgroundInFakeGame(xForFakeGame);

            if (xForFakeGame==-accelerationInFakeGame*9)
            {
                xForFakeGame = 0;
            }
            else
            {
                xForFakeGame = xForFakeGame - accelerationInFakeGame;
            }

            if (GetAsyncKeyState(0x57))
            {
                if (yHero==FIRST_LINE+100)
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero-200;
                }
            }

            if (GetAsyncKeyState(0x53))
            {
                if (yHero==THIRD_LINE+100)
                {
                    yHero = yHero;
                }
                else
                {
                    yHero = yHero+200;
                }
            }

            drawHeroWithGrafics(xHero, yHero, false, RIGHT);

            if (stepInFakeGame>10 and stepInFakeGame<210)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-10), FIRST_LINE, OBJECT_FENCE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-10), THIRD_LINE, OBJECT_FENCE);

                if (stepInFakeGame>155 and stepInFakeGame<175 and (yHero==FIRST_LINE+100 or yHero==THIRD_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>100 and stepInFakeGame<340)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-100), SECOND_LINE, OBJECT_ROCK);

                if (stepInFakeGame>245 and stepInFakeGame<315 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>200 and stepInFakeGame<640)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-200), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-240), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-280), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-320), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-360), FIRST_LINE, OBJECT_PUDDLE);

                if (stepInFakeGame>345 and stepInFakeGame<575 and yHero==FIRST_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>280 and stepInFakeGame<600)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-280), SECOND_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-320), SECOND_LINE, OBJECT_PUDDLE);

                if (stepInFakeGame>425 and stepInFakeGame<535 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame==580)
            {
                accelerationInFakeGame = 10;
            }

            if (stepInFakeGame>600 and stepInFakeGame<700)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-600), SECOND_LINE, OBJECT_FENCE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-600), THIRD_LINE, OBJECT_FENCE);

                if (stepInFakeGame>672 and stepInFakeGame<677 and (yHero==SECOND_LINE+100 or yHero==THIRD_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>630 and stepInFakeGame<750)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-630), SECOND_LINE, OBJECT_ROCK);

                if (stepInFakeGame>702 and stepInFakeGame<737 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>650 and stepInFakeGame<750)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-650), FIRST_LINE, OBJECT_FENCE);

                if (stepInFakeGame>722 and stepInFakeGame<727 and yHero==FIRST_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>670 and stepInFakeGame<810)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-670), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-690), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-690), SECOND_LINE, OBJECT_VOID);

                if (stepInFakeGame>742 and stepInFakeGame<777 and yHero==THIRD_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }

                if (stepInFakeGame>762 and stepInFakeGame<777 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame==810)
            {
                accelerationInFakeGame = 20;
            }

            if (stepInFakeGame>815 and stepInFakeGame<905)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-815), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-825), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-835), FIRST_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-845), FIRST_LINE, OBJECT_PUDDLE);

                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-815), THIRD_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-825), THIRD_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-835), THIRD_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-845), THIRD_LINE, OBJECT_PUDDLE);

                if (stepInFakeGame>851 and stepInFakeGame<899 and (yHero==FIRST_LINE+100 or yHero==THIRD_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>870 and stepInFakeGame<930)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-870), SECOND_LINE, OBJECT_ROCK);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-870), THIRD_LINE, OBJECT_ROCK);

                if (stepInFakeGame>906 and stepInFakeGame<924 and (yHero==SECOND_LINE+100 or yHero==THIRD_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>890 and stepInFakeGame<960)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-892), FIRST_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-892), SECOND_LINE, OBJECT_VOID);

                if (stepInFakeGame>927 and stepInFakeGame<944 and (yHero==FIRST_LINE+100 or yHero==SECOND_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>913 and stepInFakeGame<1043)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-913), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-923), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-933), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-943), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-953), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-963), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-973), THIRD_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-983), THIRD_LINE, OBJECT_VOID);

                if (stepInFakeGame>949 and stepInFakeGame<1037 and yHero==THIRD_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>915 and stepInFakeGame<995)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-915), SECOND_LINE, OBJECT_PUDDLE);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-925), SECOND_LINE, OBJECT_PUDDLE);

                if (stepInFakeGame>951 and stepInFakeGame<979 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>947 and stepInFakeGame<1007)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-947), FIRST_LINE, OBJECT_FENCE);

                if (stepInFakeGame>983 and stepInFakeGame<991 and yHero==FIRST_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>960 and stepInFakeGame<1020)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-960), SECOND_LINE, OBJECT_ROCK);

                if (stepInFakeGame>996 and stepInFakeGame<1014 and yHero==SECOND_LINE+100)
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }

            if (stepInFakeGame>983 and stepInFakeGame<1043)
            {
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-983), FIRST_LINE, OBJECT_VOID);
                drawObjectInFakeGame(MAX_X-accelerationInFakeGame*(stepInFakeGame-983), SECOND_LINE, OBJECT_VOID);

                if (stepInFakeGame>1019 and stepInFakeGame<1037 and (yHero==FIRST_LINE+100 or yHero==SECOND_LINE+100))
                {
                    fakeGame = false;
                    fakeLoose = true;
                }
            }
        }

        if (fakeLoose)
        {
            txSetFillColor(TX_WHITE);

            for (int i=0; i<QUANTITY_LOADING_IN_LOOSE; ++i)
            {
                txSetColor(TX_BLACK);
                txCircle(500, 500, 100);
                txSetColor(TX_WHITE);
                txRectangle(xLoading-50, yLoading-50, xLoading+50, yLoading+50);

                if (i<20)
                {
                    xLoading = xLoading-10;
                }
                else
                {
                    xLoading = xLoading+10;
                }

                if (i<10 or i>30)
                {
                    yLoading = yLoading+10;
                }
                else
                {
                    yLoading = yLoading-10;
                }

                txSleep(50);
                txClear();
            }

            txSelectFont("Comic Sans MS", 200);
            txSetColor(TX_BLACK);
            txDrawText(100, 100, 900, 900, "–≈ À¿Ã¿");
            txSleep(250);

            for (int i=0; i<BACKGROUND_OF_ADVERTISING; ++i)
            {
                txSleep(250);
                txSetFillColor(TX_WHITE);
                txClear();

                for (int j=0; j<BACKGROUND_OF_ADVERTISING; ++j)
                {
                    selectColorInFakeMenu(&numberColorInFakeMenu);
                    txSelectFont("Comic Sans MS", 120);
                    txDrawText(-100-50*j, 10+140*j, 1600-50*j, 10+140*(j+1), "–≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿ –≈ À¿Ã¿");
                }

                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);
                txRectangle(-100, 150+140*i, 1100, 1100);

                txSelectFont("Comic Sans MS", 200);
                txSetColor(TX_BLACK);
                txDrawText(100, 100, 900, 900, "–≈ À¿Ã¿");
            }

            for (int i=0; i<FIRST_ADVERTISING; ++i)
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);
            }

            while (!(txMouseX()>900 and txMouseY()<100 and txMouseButtons()==1))
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawXButtonInFakeGame(900, MIN_Y);
            }

            for (int i=0; i<FIRST_ADVERTISING; ++i)
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);
            }

            while (!(txMouseX()>400 and txMouseY()>200 and txMouseX()<500 and txMouseY()<300 and txMouseButtons()==1))
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);

                drawXButtonInFakeGame(400, 200);
            }

            for (int i=0; i<SECOND_ADVERTISING; ++i)
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);
                drawBoxOfAdvertising(450, 250);
            }

            while (!(txMouseX()>700 and txMouseY()>500 and txMouseX()<800 and txMouseY()<600 and txMouseButtons()==1))
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);
                drawBoxOfAdvertising(450, 250);

                drawXButtonInFakeGame(700, 500);
            }

            for (int i=0; i<THIRD_ADVERTISING; ++i)
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);
                drawBoxOfAdvertising(450, 250);
                drawBoxOfAdvertising(750, 550);
            }

            while (!(txMouseX()>450 and txMouseY()>450 and txMouseX()<550 and txMouseY()<550 and txMouseButtons()==1))
            {
                drawAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(950, 50);
                drawBoxOfAdvertising(450, 250);
                drawBoxOfAdvertising(750, 550);

                drawXButtonInFakeGame(450, 450);
            }

            for (int i=0; i<THIRD_ADVERTISING; ++i)
            {
                drawFullAdvertisingBackground(&numberColorInFakeMenu);
            }

            for (int i=0; i<FOURTH_ADVERTISING; ++i)
            {
                drawFullAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(100, 800);
            }

            for (int i=0; i<FOURTH_ADVERTISING; ++i)
            {
                drawFullAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(100, 800);
                drawBoxOfAdvertising(200, 300);
            }

            for (int i=0; i<FOURTH_ADVERTISING; ++i)
            {
                drawFullAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(100, 800);
                drawBoxOfAdvertising(200, 300);
                drawBoxOfAdvertising(800, 400);
            }

            for (int i=0; i<FOURTH_ADVERTISING; ++i)
            {
                drawFullAdvertisingBackground(&numberColorInFakeMenu);

                drawBoxOfAdvertising(100, 800);
                drawBoxOfAdvertising(200, 300);
                drawBoxOfAdvertising(800, 400);
                drawBoxOfAdvertising(500, 980);
                drawBoxOfAdvertising(240, 130);
                drawBoxOfAdvertising(960, 560);
            }

            drawEpilogue(GREED);
        }

        txSleep(50);
        txSetFillColor(TX_WHITE);
        txClear();
    }
}
