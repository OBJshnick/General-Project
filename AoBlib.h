#include "TXlib.h"


CONST int QUANTITY_FENCE_IN_START_PLACE = 7;
CONST int QUANTITY_RECTANGLES_IN_PLAY = 19;
CONST int QUANTITY_RECTANGLES_IN_TRAINING = 8;
CONST int QUANTITY_BRIDGES_IN_GRAFIC = 3;
CONST int QUANTITY_BRIDGES_IN_SECRET = 3;
CONST int QUANTITY_BRIDGES_IN_STORY = 2;
CONST int QUANTITY_RECTANGLES_IN_UPDATE = 21;
CONST int QUANTITY_ROCKS_IN_MECHANIC = 20;
CONST int QUANTITY_RECTANGLES_IN_LOADING = 30;
CONST int QUANTITY_RECTANGLES_IN_DIALOG = 5;
CONST int ACCELERATED_TIME = 20;
CONST int QUANTITY_RECTANGLES_IN_MONOLOGUE = 120;
CONST int QUANTITY_BRIDGES_IN_FIRST_RIVER = 3;
CONST int QUANTITY_BRIDGES_IN_SECOND_RIVER = 4;
CONST int TIME_FOR_PRESS_SPACE = 200;
CONST int SPEED_ARROWS_IN_DIALOG = 5;
CONST int TIME_IN_FINALLY_MONOLOGUE = 5000;
CONST int INCREASE_IN_TEXT = 100;
CONST int MOVEMENT_OT_SHADOW = 20;
CONST int RECTANGLES_FOR_START_FAKE_GAME = 11;
CONST int QUANTITY_LOADING_IN_LOOSE = 45;
CONST int QUANTITY_WORDS_IN_BOX_OF_ADVERTISING = 5;
CONST int QUANTITY_ERRORS_IN_ERROR = 10;
CONST int QUANTITY_POINT_IN_WORD_IN_ERROR = 3;


enum DirectionHero {DOWN, RIGHT, UP, LEFT};
enum DirectionSecret {MOVE_UP, MOVE_DOWN};
enum ScreenSize {MIN_X = 0,
                 MIN_Y = 0,
                 MAX_X = 1000,
                 MAX_Y = 1000
                 };
enum ProhibitionForHeroMovement {LEFT_X = 75,
                                 RIGHT_X = 925,
                                 UP_Y = 75,
                                 DOWN_Y = 925
                                 };
enum CenterForHero {CENTER_X = 500,
                    CENTER_Y = 500
                    };
enum QuantityInBridge {BOARDS = 5,
                       NAILS = 5
                       };
enum QuantityBridgesInMechanic {LINE_X = 3,
                                LINE_Y = 5
                                };
enum QuantityFencesInSecretPlace {FENCES_IN_FIRST_LOCATION_1 = 14,
                                  FENCES_IN_FIRST_LOCATION_2 = 10,
                                  FENCES_IN_FIRST_LOCATION_3 = 8,
                                  FENCES_IN_FIRST_LOCATION_4 = 6,
                                  FENCES_IN_SECOND_LOCATION_1 = 16,
                                  FENCES_IN_SECOND_LOCATION_2 = 4,
                                  FENCES_IN_THIRD_LOCATION_1 = 16,
                                  FENCES_IN_THIRD_LOCATION_2 = 12,
                                  FENCES_IN_THIRD_LOCATION_3 = 10,
                                  FENCES_IN_THIRD_LOCATION_4 = 4,
                                  FENCES_IN_FOURTH_LOCATION_1 = 12,
                                  FENCES_IN_FOURTH_LOCATION_2 = 4
                                  };
enum QuantityFencesInStoryPlace {FENCE_BOARDS = 2,
                                 FIRST_FENCES = 8,
                                 SECOND_FENCES = 9,
                                 THIRD_FENCES = 4,
                                 FOURTH_FENCES = 20,
                                 FIFTH_FENCES = 10
                                 };
enum QuantityFlaresInExit {FLARES_WITH_RECTANGLES_FIRST = 1,
                           FLARES_WITH_RECTANGLES_SECOND = 6,
                           FLARES_WITH_RECTANGLES_THIRD = 4,
                           FLARES_WITHOUT_RECTANGLES = 4
                           };
enum Updates {LOADINGS, GRAFIC, MECHANIC, SECRETS, STORY};
enum MovementWords {ADVENTURE = 50,
                    ALPHA = 100
                    };
enum TypesOfDialogs {THE_APPEARANCE_OF_HERO,//
                    HERO_RETURN_TO_THE_FIRST_LOCATION,
                    HERO_FIRST_COMES_TO_THE_FORK,
                    HERO_FIRST_SEES_A_STONE_WITHOUT_A_PICKAXE,
                    HERO_SEES_A_STONE_WITHOUT_A_PICKAXE,
                    HERO_FIRST_COMES_TO_THE_RIVER_WITHOUT_BRIDGES,
                    HERO_FIRST_COMES_TO_AN_EMPTY_CITY,
                    HERO_FIRST_COMES_TO_A_PLACE_OF_GREED,
                    HERO_FIRST_READS_AN_ADVERTISING_CONTRACT,
                    HERO_READS_AN_ADVERTISING_CONTRACT,
                    HERO_REFUSES_ADVERTISING_CONTRACT,
                    HERO_AGRESS_TO_ADVERTISING_CONTRACT,
                    DEVELOPER_TRAINS_PLAYER,
                    HERO_FIRST_COMES_IN_SITY_WITH_CARPENTER,
                    HERO_FIRST_TALK_WITH_CARPENTER,
                    HERO_TALK_WITH_CARPENTER,
                    HERO_TALK_WITH_CARPENTER_ABOUT_STONE,
                    HERO_FIRST_SEE_NEW_BRIDGE,
                    HERO_FIRST_COMES_IN_CITY_WITH_ERROR,
                    HERO_FIRST_TALK_WITH_ERROR,
                    HERO_TALK_WITH_ERROR,
                    HERO_TALK_WITH_CARPENTER_ABOUT_ERROR,
                    HERO_FIRST_COMES_TO_SECOND_RIVER,
                    HERO_FIRST_COMES_IN_SITY_WITH_WORKER,
                    HERO_FIRST_TALK_WITH_ARCHITECT,
                    HERO_TALK_WITH_ARCHITECT,
                    HERO_TALK_WITH_CARPENTER_ABOUT_ARCHITECT,
                    HERO_TALK_WITH_ARCHITECT_ABOUT_CARPENTER,
                    HERO_TALK_WITH_ARCHITECT_ABOUT_ERROR,
                    HERO_FIRST_TALK_WITH_ENGINEER,
                    HERO_TALK_WITH_ENGINEER,
                    HERO_TALK_WITH_CARPENTER_ABOUT_ENGINEER,
                    HERO_TALK_WITH_ENGINEER_ABOUT_CARPENTER,
                    HERO_TALK_WITH_ENGINEER_ABOUT_ERROR,
                    HERO_FIRST_TALK_WITH_LIBRARIAN,
                    HERO_TALK_WITH_LIBRARIAN,
                    HERO_TALK_WITH_CARPENTER_ABOUT_LIBRARIAN,
                    HERO_TALK_WITH_LIBRARIAN_ABOUT_CARPENTER,
                    HERO_TALK_WITH_LIBRARIAN_ABOUT_ERROR,
                    HERO_FIRST_TALK_WITH_QUESTIONNAIRE,
                    HERO_TALK_WITH_QUESTIONNAIRE,
                    HERO_TALK_WITH_CARPENTER_ABOUT_QUESTIONNAIRE,
                    HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_CARPENTER,
                    HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_ERROR,
                    HERO_FIRST_COMES_IN_SITY_WITH_MINER,
                    HERO_FIRST_TALK_WITH_MINER,
                    HERO_TALK_WITH_MINER_ABOUT_QUEST,
                    HERO_GET_AWARD_FROM_MINER,
                    HERO_TALK_WITH_MINER,
                    HERO_TALK_WITH_CARPENTER_ABOUT_MINER,
                    HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_MINER,
                    HERO_TALK_WITH_MINER_ABOUT_CARPENTER,
                    HERO_TALK_WITH_MINER_ABOUT_QUESTIONNAIRE,
                    HERO_TALK_WITH_MINER_ABOUT_ERROR,
                    HERO_FIRST_COMES_IN_SECRET_PLACE,
                    HERO_FIND_SECRET_BRIDGE,
                    HERO_IN_EMPTY_LOOT_PLACE,
                    HERO_IN_LOOT_PLACE_WITH_CHEST_WITHOUT_QUEST,
                    HERO_IN_LOOT_PLACE_WITH_CHEST_WITH_QUEST,
                    HERO_DESTROY_STONE,
                    HERO_WENT_TROUGH_FENCE,
                    HERO_FIRST_SEE_SECRET_BRIDGE,
                    HERO_MEET_THE_END
                    };
enum CoorditnatesOfTextInDialog {X_FOR_TEXT = 20,
                                BOTTOM_Y_FOR_TEXT = 800,
                                TOP_Y_FOR_TEXT = 900
                                };
enum QuantityFencesInGame {TWO_FENCES_IN_GAME = 2,
                          FOUR_FENCES_IN_GAME = 4,
                          SIX_FENCES_IN_GAME = 6,
                          EIGHT_FENCES_IN_GAME = 8,
                          TWELVE_FENCES_IN_GAME = 12,
                          FOURTEEN_FENCES_IN_GAME = 14,
                          SIXTEEN_FENCES_IN_GAME = 16,
                          EIGHTEEN_FENCES_IN_GAME = 18,
                          TWENTY_FENCES_IN_GAME = 20
                          };
enum QuantityRocksInCobblestone {ROCKS_ON_X = 10,
                                ROCKS_ON_Y = 5
                                };
enum ColorsInFakeMenu {RED,
                      ORANGE,
                      YELLOW,
                      GREEN,
                      LIGHT_BLUE ,
                      BLUE,
                      PURPLE
                      };
enum YInFakeGame {FIRST_LINE = 200,
                 SECOND_LINE = 400,
                 THIRD_LINE = 600
                 };
enum TypeOfLet {OBJECT_ROCK,
               OBJECT_FENCE,
               OBJECT_PUDDLE,
               OBJECT_VOID
               };
enum AdvertisingInFakeGame {BACKGROUND_OF_ADVERTISING = 7,
                           FIRST_ADVERTISING = 8,
                           SECOND_ADVERTISING = 6,
                           THIRD_ADVERTISING = 4,
                           FOURTH_ADVERTISING = 2
                           };
enum QuantityFencesInFakeGame {OBJECT = 4,
                              BACKGROUND = 25
                              };
enum CharacterNames {HERO,
                    CARPENTER,
                    ARCHITECT,
                    ENGINEER,
                    LIBRARIAN,
                    QUESTIONNAIRE,
                    MINER
                    };
enum TypesOfEndings {GREED,
                    CREATION
                    };


void drawHeroWithoutGrafics (int x, int y, bool heroInPuddle);
void drawHeroWithGrafics(int x, int y, bool heroInPuddle, enum DirectionHero direction);
void selectionPortalInStory(int *xHero, int *yHero, bool heroInPuddle, int portal);
void drawFog(int x, int y);
void drawBridge(int x, int y);
void drawGrass(int x, int y, int type);
void drawFence(int x, int y, int direction);
void drawFenceBoard(int xLeft, int yLeft, int xRight, int yRight);
void drawPuddle(int xLeft, int yLeft, int xRight, int yRight);
void drawWave(int x, int y);
void drawRock(int x, int y);
void placeOfGreed();
void drawPortal(int x, int y);
void drawSecret(int x, int y, int *phaseSecret, enum DirectionSecret *directionSecret);
void drawDeveloperMonologue (int *developerMonologueNumber);
void drawGettingSecret(int *phaseSecret);
void drawGettingUpdate(enum Updates update);
void drawStartPlaceWithoutGrafics();
void drawStartPlaceWithGrafics();
void drawBackgroundWithGrafic();
void drawBackgroundInTheGame();
void drawBeginningInTheGame();
void drawForkInTheGame(bool destroyRock);
void drawSecondRiverInTheGame();
void drawTownInTheGame(int secrets, enum Updates update);
void drawFirstRiverInTheGame();
void drawPlaceOfGreed();
void exit();
void play();
void training();
void pressShift(int *acceleration);
void selectColorInFakeMenu(int *numberColorInFakeMenu);
void selectPositionGrafic(int xHero, int yHero, int *positionGrafic);
void drawGraficPlace(int xLeft, int yLeft, int xRight, int yRight, int number, int type, int *positionGrafic);
void drawSecretPlaceWithoutGrafics(int level);
void drawSecretPlaceWithGrafics(int level, bool mechanicUpdate);
void drawStoryPlaceWithoutGrafics();
void drawStoryPlaceWithGrafics(bool mechanicUpdate);
void drawLoading(enum Updates updatesSequence, int time1, int time2, int time3, int time4, int time5, int rectangleX1, int rectangleX2, int rectangleX3, int rectangleX4, int rectangleX5);
void drawGameDialog(enum TypesOfDialogs type, bool *firstBugInGame, bool *normalGame);
void drawArrowsInDialog(bool *firstBugInGame, bool *normalGame);
void drawArrow(int x, int y);
void drawSelectInContract(bool *firstBugInGame, bool *normalGame);
void drawBackgroundInFakeGame(int x);
void drawObjectInFakeGame(int x, int y, enum TypeOfLet type);
void drawBoxOfAdvertising(int x, int y);
void drawXButtonInFakeGame(int x, int y);
void drawAdvertisingBackground(int *numberColorInFakeMenu);
void drawFullAdvertisingBackground(int *numberColorInFakeMenu);
void drawLetter(bool scale);
void drawSecondRiverInTheGame(int secrets);
void drawSecretPlaceInTheGame();
void drawNameFoSpeaker(enum CharacterNames name);
void drawErrorInNormalGame();
void drawTheEndPlace();
void drawEpilogue(enum TypesOfEndings theEnd);

/**
    1) type - type of dialogue
    2) firstBugInGame - error check with dialog arrows
    3) normalGame - game type check
**/
void drawGameDialog(enum TypesOfDialogs type, bool *firstBugInGame, bool *normalGame)
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    for (int i=0; i<QUANTITY_RECTANGLES_IN_DIALOG; ++i)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 40+40*i);
        txRectangle(MIN_X, 960-40*i, MAX_X, MAX_Y);
        txSleep(100);
    }

    drawNameFoSpeaker(HERO);

    if (type==THE_APPEARANCE_OF_HERO)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- \"��� ��������� ����� ��� ���� ����� �������� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���������� �� �������� �� ���������, ����������.\"");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, � ������� � �������, ������ ���� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ��� ��� � ����������� ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ���� �������� ��� ����� ����� ��� ����� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ���� ������������ ��������� �� ����� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� � �������� �� �� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ����� �������� �� ���������� ������� �����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ׸��, ���� � ������� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ����, ������ ����� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_TO_THE_FORK)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���. ��� ����� ���� ������� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ���� ��� ���� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����������, ��� ������ ���� ���� �� ������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_RETURN_TO_THE_FIRST_LOCATION)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����������, �� ����� ������ �� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ����, ���� ����� �����, �� ���-������ ����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txSleep(1000);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ���. � ��������� ��� � ��� ������ ���� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� � �� ��������� ������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_SEES_A_STONE_WITHOUT_A_PICKAXE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ������ ������������ �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ���� ��� ���� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txSleep(1000);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ��� ���. ������, ��� � ��� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �������� �� ����������� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_SEES_A_STONE_WITHOUT_A_PICKAXE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��-�������� �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ����� ������� ������� ��.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � �� ��� ����� � ��� � ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� �� ��������, ���� � ���-�� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_TO_THE_RIVER_WITHOUT_BRIDGES)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, ���� �����-�� ������������ - ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����, ��� � �� ���� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_TO_AN_EMPTY_CITY)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ������ �������. ���, ��������� � ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ������ ���-�� ����?");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_TO_A_PLACE_OF_GREED)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ������� ����� �������, ��� ��������� ������� � ������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ��� ���� �� �����-�� �������. ���� ������ ��� ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_READS_AN_ADVERTISING_CONTRACT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����-��... �������? ����� � ���� ���� ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���-���-���, ���������� �������... ��-��-��, ��� ������...");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ����������, ��� � ���� �� ����� �����, � ���� ��� �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ������������� ������ �����! � �� ���� ����� ���������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, ������� ����� �������� ���������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ��� �����, ������ ��� �������� ����� 0.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ��������: ����� ��� ����� �������� ��� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�����, � ����� ����� � ���� ����� ���������?");
        drawSelectInContract(firstBugInGame, normalGame);
    }

    if (type==HERO_READS_AN_ADVERTISING_CONTRACT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ��������: ����� ��� ����� �������� ��� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�����, � ����� ����� � ���� ����� ���������?");
        drawSelectInContract(firstBugInGame, normalGame);
    }

    if (type==HERO_AGRESS_TO_ADVERTISING_CONTRACT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��������������� - ��� ������������ ����, ����� � ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ���� ������ �� �����, � � ����� � �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_REFUSES_ADVERTISING_CONTRACT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ ������ ��� ���� �������� �������. ��� ����� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ���������� ����� � ���� ���-������ ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==DEVELOPER_TRAINS_PLAYER)
    {
        txSetFillColor(TX_BLACK);
        txSetColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, 200);

        txSetFillColor(TX_WHITE);
        txSetColor(TX_WHITE);
        txSelectFont("Times New Roman", 175, 40);
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "������� ���������:");
        txSelectFont("Times New Roman", 100, 12);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �����, ������. ���� ���� �������� �� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ���� ���� ������ �������, ��� ��� ���� �������� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "׸��, ��� �� ������� ���������� ������ ��� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� ��� �������?.. �, ���������, ������ �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "���������� ������������ �����: W/� - ������� �� ������� �������,");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "S/� - ������� �� ������ �������. ����� �� ���� ����� �����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, �����, �������, �� ��������, ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ��� ������! ���������� �������� �� ����!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_IN_SITY_WITH_CARPENTER)//1//
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ������ ��������� ������ - ���!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ��� ��� �� ������ ���������, ��� �� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������? ����� ���� ���-������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �? ��� ���?.. ���! ����� ����� ������ ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������, ������ �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ �� �������� �����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ��� �� ��� �����? ���� ����� ������ �.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ����� � ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���-�� ��� �� ��������� � ��������� �� ��� ������");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��� �� ���������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��, ��� � �������, �������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���... ����� ������� ��������");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �����, ��� ��� ��������. ����� ��, ���� ��� � ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� �... ������ �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ������ ��� �������� � �������, ������ ��� � �������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � �� ���� ����� ����� ���������, ������ � ������ ����� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ������, ��� �������� ���� �����, ��� � �� ���� ��������� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ���� ������������� ������ ��� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ������ �� ����� ����� ��������� �����. ������ � ���� ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� �� ������� ��� ���� ��� �������, �� ���� ����� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ������� ����� ���� ����������� �� ������ ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ��� ��� �� ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ����. ��������� ������ ����... � � ������ �� �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���-�� � ���� ���� �����. ׸��, ������ �� �����...");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �������. � ����� �����. ����������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� �������, ���� ����� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, ������� �������������, � ���� �����... �� �����...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ���� ��������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������������! ��� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������, ���� ��-��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � ���� ����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ������ ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_STONE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ��� �� ������, ������� ����� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ��� ���� ���-������ ����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �������, � ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ��, ��� � ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����. � �� ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_SEE_NEW_BRIDGE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ����-�� ������� ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ���-�� ��� ���������, ����� ������ �� ��������� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_IN_CITY_WITH_ERROR)//2//
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ����� ��� ����! ������ ������������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ���� ��� �� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������? ����� ���� ���-������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txSleep(1000);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��� �����? � ���� ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� �� � �������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txSleep(1000);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ �� �������...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, ����� � �����? ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawErrorInNormalGame();
    }

    if (type==HERO_TALK_WITH_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ���. ��� ���� �������� � �� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "׸��, ��� �� � ��� �� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��� � ���� �� �������� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� ���� �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� � ������ ������. �����, ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � ��� �� ������� � ������ �� ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����������, �� ����� ���, ��� �� �����, � ����� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ������, ��� � ������� ��� ���� ����� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �������! �������, �� ������ ��� ���������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_IN_SITY_WITH_WORKER)//3//
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��� ����! ����������� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ��� �� ���������� NPC.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_ARCHITECT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, �� ����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, � �� ���������? ����� ����� ������ �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, � ����������, �� �������� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ ������ � ��������� �� ��� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, ����� �������� ���������� �� ������ ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� ����, ��� ��� ���������� ������, ��?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, ��� ������� � ������! ��� ������ ��� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ��� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� �� � �� ������, ��� ��� ������� ������������ �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �� �� ���� ������� � �������, ���� �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� � ��, ��� ���� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������� ����� �������, �� ����� �� ������� �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������� ��������, ������� ��������� �� ������ �� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������� ���� ��� ������ ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �����, ��� ������� � ���� ��� ������ ���� ������ �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � ������ �������� ��� �� ������ �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���������� ������� ����� ���������� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ � ��� ��� ����, ����� �������� ���� ��������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� �������� ����� ����� ���� � ������� ������� ������ �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � �� �����, ��� ��� ��� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������� ����, � �� ���� ������, ��� �� �������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � ��� �������, ��� �� ������ �� ������� � �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����, ������ ��� �� ������ ���� \"������\".");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�����, � ����� ��������� ��� �������� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����, ��� �� ������� �������� ��� ������� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� �� ����� ����� ���������. �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ARCHITECT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������. ���� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ���, ������������ ����� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ��� �����? ��������? ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � �����, ��� ��� ����� ������, �� � ���� �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � ���� ��� �� ���? ������ ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������ ������ ��� ����� ��� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_ARCHITECT)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ������� �� �����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ���������� ��� ����������. �� ����� ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� � ��� ������ ��� ����, ��� �� ������� ����� ��� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ���� ����� ������ ��������. �� � �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ���������� ��� ����, ������� �� ������ ��� ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����������, �� ��� ������ ������ �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ��� ������ ���������, ����� � ������ ����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ����, ��� �� ��� ��������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ARCHITECT_ABOUT_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ������� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��� ���������� ���� �������. ");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� ����� ������������ ����� ���. ������� ��, ����� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ARCHITECT_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� �������� � ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, ����� �������, ������ ������ �� ������� �����, ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, ��� �����! � ���������� ��������� ������ � ���������� ��!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������, ����� �������� ������� � ��������!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, � ��� �� ������ ������� � ��� ���������� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �����-�� ������ ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �� ��� ���. � � ��� �� ����, ��� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� ��������� ��� � ����������, ����� �� ��� ����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� � �� ��� ��� ���������. �� ��� ��� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� � ������ �� ��������. �� ����� ������ �� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ��� �������� ������������ �������, ������� � �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ ������� � ���, ��� ��� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ARCHITECT);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��-�����, ��� ������ ���. ��-������� ����, � �� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� ������ � ��� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ��� �� ������� ��� ������������ ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_ENGINEER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������������, �� �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��� �. � �� ���? ���� � ����� ������ �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ �� �����-������ ��������������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ����� �����, � �����, � �������� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ����� ����� � ��������� �� ��� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� � ����� �� �� ����� ����������� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������. ������ �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� �� ������� � ���� ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ���? ��, ���� �����, �� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � ��� �������������. �� �� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ���, ��� �� ����� ������� �� ����� ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� � � �������� �������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������ �����, � � ��� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� � ����� ��� ������ � ��������� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ���� � ���� ������ ���, ����� ����� ���� ������� ���� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, ������ �� ������ ��� ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ ���������� ��� �������� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������ ��� ��� ��������� �� ������. ����� �� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �����, �����. �� ��� ����, � �����, ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����-�����, �� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, �������, �� ������ ��������� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ENGINEER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ��� � ���� ����? ��� ���������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ��� ������. ��� �� �������, �� �������� ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ����� ���������, �� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� ��� �����. � � ���� ��� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������ ������. ����� �� ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_ENGINEER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ������� �� ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��������? �, ��� ��� ��������. �� ��� �������� � ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� � � ��� ����� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ �� ����� �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � �� ����. �� ���� �� ��������� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� ��� ��-�� ����, ��� �� ����� ��������� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������, ��� ��� ����� ����� ��� ���-�� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������ �� �����, �� ������� ����� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ �� ���, � �� ������� ������� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���������! ���� ��� ������ �� ��� ����� ��������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ENGINEER_ABOUT_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ���������� �������. ���� �� �� ��������, �� �� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��������� � ���������, ���������, ��� �� ���� �� ���� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_ENGINEER_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ � ��� ���������� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � � ��� �� ���� �� �����. �� ������ ����� � ����� ������ ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� �� ������, �� ����� �� ������������. ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���������� � ��� ����������, � �� ���� ���� �� ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ���� ����� �����! �� ����� ��� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ������ ��� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����, ��� � ���� ���������, �� ����������� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ �� ��� �����? �� �������, � ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � �����, ��� ��� �� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(ENGINEER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �������, � ������� � ���� ��-���� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_LIBRARIAN)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ����� ���� ���-������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����������? ��� �� ���� �����? ��� ��?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������ ����� ��������� ��� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ������� ����� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ����� �������� �� ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ������, � ������ ��� �� ���� ��� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ���� � ������ �� ����, �� ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������� �������� ���� ��������: ��� ��?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��������, � �������� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ����� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �? ��, �����, ����� �������������. � - ������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� ��� ����, ���� � ���� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ������ �������������� ���� ����� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ � ����� ������ �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ � ����� ��������� ����� ��� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������, ��� ������� ���� ���� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��������� ������: ��� �� ���� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� �������� �����? ");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �� ���, ��� � ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ������ �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��, ������. ���� �������� ������� ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� �� ������� �����? ������ �� ���� ��� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �����. ���, �������...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ � ��� ����, �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���������, ������ �������������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� ������� �...");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������-������, ��� ��� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� �������� �� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � � ���� ����� �����, ����� ���������� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �� �������, ������ ����. � ���� ������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_LIBRARIAN)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ���� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� � ���� ���� ���� ����� ������ ��� ���� ������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� ������ ������ ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ������? ��, ���� ������ �������..");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�, � ���� �� ���� �������� �� ���� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ׸��, � ���� �� ����� �� ����. ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� �������, ��� ���� � �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����, ���� � ����������� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_LIBRARIAN)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������� � ������������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������ ������, ����������������, �� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ������ ��� ���� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ �� ��������. ��� �� ������� �� ����, � ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ���� ����, �����, �����. ������� �� ������ �� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� ���� ����� �� ����. �� �� ����� ������ ������������� � ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ����� ��� ������������� ����� ���� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �������, ��� ����� ���������� � �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� � �� ���� ��������!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �� ������ ��� �����, ����� � ��� ��������� ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ��� ������ �� �����-�� ������� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ������, ��� ���� ���� ��� ������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �������! �������, �� ��� ��������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_LIBRARIAN_ABOUT_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ���������� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �������, ��� �� ���������� ���� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ � ������ ��� ������ ��� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��������� � ��������� �� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� ������� �� ������� ��� �� ������ ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������, ����� ������� ����� - ��� ����� ��� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������, ����������, ����������, ������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ������ ����� � ������ ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�����, �� � ��� ��� �������, ����� � ��� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� �� ����������� ���� �� ��������� ����� ���� �������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ����� ������������ �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� ������ ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_LIBRARIAN_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ ���������� � ��� ���������� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �� ���� ������ �� �������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � � ����� ����? � �����, �� ������ � �������� �� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� �����-�� ��������. ����� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� �� ��������� ������� ��� ������� � �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� �� � �� ���������� � ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� � ����� ��� ���� ������ ���������, � �� ���� ���������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ����� ���� ���������� ��� �������� ���������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� � ���� ��������� �����, ��� � ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �� ���� ���� �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(LIBRARIAN);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����??? �� ������� �� ���-�� �����������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ����� ����� �������� ��� �������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_QUESTIONNAIRE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ����� ���� ���-������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���-��, ������� ���-�� �����. ����� � �������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ������ ������� ������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���... ����� ����� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ������ �����, � �� �� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, � �� ��� � ���������. ����� ������ �������...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ������. �� ���� �� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ��� ��������� ������� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� �� ����. ����� ����� �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������� ������ ��� ���� ����� �� ������ �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� �� ������ � ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��������� ���� �� ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ���� �� ���������� ������� ��� ���!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ����� ��������. ��...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � �����! �� ����� ���� ����� �������� ���������,");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���������, ��������� � ������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��-�� ����� ����� ������������ �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �� �� ����� ��� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ������� ������, ������� ���� �����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����. � ������� ������, ������� ���-�� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ����� ������ ��� ����� � ������� �������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ����� ����� � ������������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��. ��������, ���������, ���?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �� ��� ����� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���? ���? �, ���� � ���, ������ �� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ����� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� ����� ������� � ������ �������...");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, ����, ����. � ���� ���� ��������� �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� � ������ ��������� � ����� ��������� � ���� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �����, �� �����. ����� ���������� ��� ���������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ��������� �� �������� ����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, �� ���� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��... ��� ���� ��� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����. � ��� ��� �� ����� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_QUESTIONNAIRE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ���� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ����� ���������. � � ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �� ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_QUESTIONNAIRE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ���������� � ����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ��������? ��, � ���� ������ ���������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� ��� �������, ��� �� ������ ������ ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� ������� ��� ������ ���������� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ ����� ��� ����������� ��� ��� �������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ����� ����� ��������, ����� ������ �� �������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ������ ������, ���?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ���, �������������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ���� �� �������� �������, ������� � �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, �� � �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ���� ������� ����� ���� � ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ � ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ����� ����� ����� �������� ����� ����� �� ����� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���-�� ������� � ������ ��� ����� ��� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ������ �� ��� ������ ����� ���� ��������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ����, �� �� ��������, ��� ������� ������ ����� ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ���������� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���������� �������. � ��� ��� ���� ������� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ��������� �� ���� ��������� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ���� ���������� ���� �� ���:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ����� ���� ������ ������ ����� ������� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���... ��... �������...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��������� � ������ �������?..");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �� ����� ���� ��� ����� ������� �������� � �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� � ����...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� ������� �������� ������� �������� ������ ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ ���������� � ��� ���������� ���� ����� ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ����� ��� ������� �������� �� ����������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������? �� � ����� �������������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � � ����� ����� ���?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ����� �������� � ��� ����������, �� ���� ���� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �������, � ��� ����� ������ ����� �����-������ �������");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������. � ���� � ������ ��������:");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ����������� ����� �������� ��� � �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ����������� �����-�� ���������� ��� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� ����� ��������� �������� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� �����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����-������ �������? �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, �� ����������� �������� ������ ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �� �� ���������. ������ � ������� ���� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_IN_SITY_WITH_MINER)//4//
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� ����� �������! ����������, � �� ����� �� � �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����, �������, � ��� �� ���������� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_TALK_WITH_MINER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ����� ���� ���-������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �? ��� �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �? �� ���? � ���� ����� ������ �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� �������� �����������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �� ����� ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, � ��� ������ ��� �� ���� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� ����� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������� ����� �� ���� ���������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, ������� ��� ������� ���� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ��� �� ����, ����� �����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ������� � �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ��� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������� �����. � ���� ����� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ����� �������, ����� ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ � ����� �� ����. �� ���� ������ ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ���� ��� ��! ���� ������ ����� � ���� ��������!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, �������� � �� ������. ������ ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ����� � ���� ����! � ���� ���� ��� ������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ��� ���� � ������ �...");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������� ���. �������� ��� ����� ���?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ��� ��� �������, �� �� ����� ���� ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����, ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � � ���� ������ ����� ���� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ������ ��� ��� �������� ������ ���� �� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ����� � ����� �� ������, ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����, ����� ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_MINER)
    {
        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������, ���� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_CARPENTER_ABOUT_MINER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������� � ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �����, ������� ��� ����� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ������ �� ���-�� ������ �� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ��� ������� ���� ����� ���������� ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ��� �������, ��� ����� ���� �������� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� ����, ��� ����� ������� ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ����� ����, ����� ����...");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� ������� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(CARPENTER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ����� ������� ������ ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� �� ��� �� ���� ������ �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� �������� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ���, ������� �� �� ��� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� ��� �����, ����� � �������� ����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� �� �������� ������, ��� �� ��� ������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_QUESTIONNAIRE_ABOUT_MINER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ������� � ������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � ���� ��� ������-�� ������ ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� ���� �� ���� ������� �� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����-��, ����� ����� �� ����� ������� �������, �� ��� ������:");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "\"�� �� ���, � ���� ���� ����� �������\"");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �������, ��� ��� �������� �� ��� ���� ��� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������� ������� �� ����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � � ��� ����� ���� �������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(QUESTIONNAIRE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �����, �� �� ��� ����� ����� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� � ������ ���� � ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_MINER_ABOUT_CARPENTER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ������ ������� � ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ������, �� ��� ��� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ���� �������, ����� � ������ ����� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ��� ����������� ��� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� ������ �����, � �� ������!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��-�����, �� �����, ����� �� ������� ���� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���-����� ������ ����� ������ ������ ��.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������ ������, � ������ �� ����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� �� ���!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_MINER_ABOUT_QUESTIONNAIRE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ ������� � ����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� ��������? �� ������� � ���� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� �� ���� �� ���� ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� ��� �������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � ���-�� �� ���� �� ��� ���������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� ��������� ������, � ����� ����� � ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� � ������ ���� ��� � ������� �� ����...");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ���� ��� ������ ������ ������ �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ����� ������ ���� ��� ������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_MINER_ABOUT_ERROR)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ��� �� ������ ������� � ���, ��� �������� ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �������� ��������. ��� ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��������� �� ����, ������ �� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����������� �����-��.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� �� ���� ���� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �, ��� ��� � ������� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ������ �� �� ��� ��� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_IN_SECRET_PLACE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ���� �� � ��� ��������? ������������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ���� �� ��� ������ ���-�� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ��� ��� ��� �������, ���� ��� �����?");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_WENT_TROUGH_FENCE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���? ���? ������ � ������ ������ �����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "׸��, �����������, � � ������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����, ���� �� � ����� ��������� �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� �������, �� ����������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIND_SECRET_BRIDGE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��� ����? �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ��� � ��������? ������ �� ����, �� �� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ��������� �� �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_TALK_WITH_MINER_ABOUT_QUEST)
    {
        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ��� ������ ����� ����?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� ��� �� �����, �� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ����� �������, ��� �� ��� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_GET_AWARD_FROM_MINER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����. ��� ���� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���! �� ������������� ��� �����!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� ��� �� ���?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� �������� ����� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, � ��� � � �� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �� ���, ��� � � ������, ����� �����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�����, ���� ��� ������ ������, ��� ���.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(HERO);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ������� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);

        drawNameFoSpeaker(MINER);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��� ���� �������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ � � ������ ���� ���� ��������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_COMES_TO_SECOND_RIVER)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��� ����������� ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�������, ��� ������ ��� ����� ������ �����.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_IN_EMPTY_LOOT_PLACE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ����� ��� ����� ��������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_IN_LOOT_PLACE_WITH_CHEST_WITHOUT_QUEST)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���-�� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "�� �����, ��� ��� ����� ��� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_IN_LOOT_PLACE_WITH_CHEST_WITH_QUEST)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, � ��� � ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "������ ���������, ��� � ��.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txSleep(1000);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ���������� ���.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��, ��� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���� �����, ������� �������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_DESTROY_STONE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��� � ���� ������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ��� ������ ������������? ������ �������?");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txSetFillColor(TX_BLACK);
        txSetColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSleep(2000);
        txSetColor(TX_WHITE);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ����� ��, ����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ����������, ��� ��� ������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_FIRST_SEE_SECRET_BRIDGE)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ���, ��� � ������ ����.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ����������, ��� �� ��� ������!");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }

    if (type==HERO_MEET_THE_END)
    {
        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �����? �� �� �� � ����������?");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "� � �� ����� � ��������, ��� ����� �������.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ������ ���� �����������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "��� ������ ������ �� ����.");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- �������, �� ��� �������� 5 ����� ��������.");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "���� ������! ��� ���� ������� �� �����!");
        drawArrowsInDialog(firstBugInGame, normalGame);

        txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- � ���� ��������!");
        txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "");
        drawArrowsInDialog(firstBugInGame, normalGame);
    }
}

void drawErrorInNormalGame()
{
    bool firstBugInGame = false;
    bool normalGame = false;

    COLORREF colorError = RGB(193, 0, 255);
    txSelectFont("Times New Roman", 90, 25, 1000);

    for (int i=0; i<QUANTITY_ERRORS_IN_ERROR; ++i)
    {
        txSetFillColor(colorError);
        txSetColor(colorError);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSetColor(TX_BLACK);

        for (int j=0; j<QUANTITY_ERRORS_IN_ERROR; ++j)
        {
            txDrawText(-400+25*j, MIN_Y+100*j, 1200+25*j, 100+100*j, "ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR");
        }

        txSetColor(colorError);
        txRectangle(MIN_X, 100+100*i, MAX_X, MAX_Y);

        txRectangle(600, 100, 900, 300);
        txSetColor(TX_BLACK);
        txDrawText(600, 100, 900, 300, "ERROR");
        txSleep(250);
    }

    drawArrowsInDialog(&firstBugInGame, &normalGame);
    txSleep(1000);

    for (int i=0; i<QUANTITY_POINT_IN_WORD_IN_ERROR; ++i)
    {
        for (int j=0; j<QUANTITY_POINT_IN_WORD_IN_ERROR; ++j)
        {
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
            txSetColor(TX_WHITE);

            if (j==0)
            {
                txDrawText(MIN_X, MIN_Y, MAX_X, MAX_Y, "���������.");
            }

            if (j==1)
            {
                txDrawText(MIN_X, MIN_Y, MAX_X, MAX_Y, "���������..");
            }

            if (j==2)
            {
                txDrawText(MIN_X, MIN_Y, MAX_X, MAX_Y, "���������...");
            }

            txSleep(250);
        }
    }

    txSetFillColor(colorError);
    txSetColor(colorError);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(500);

    txSetFillColor(TX_GRAY);
    txSetColor(TX_GRAY);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSetColor(TX_LIGHTGRAY);
    txDrawText(MIN_X, MIN_Y, MAX_X, MAX_Y, "���������...");
    txSleep(2000);

    txSetFillColor(TX_WHITE);
    txClear();
    txSleep(1000);
}

/**
    1) theEnd - ending type
**/
void drawEpilogue(enum TypesOfEndings theEnd)
{
    txSleep(2000);
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(1000);

    txSelectFont("Times New Roman", 60, 20);
    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "����������, �� ������� ����. \n���� ��������� ���������, ��� ��� ������.\n�� �� � ����� ������.");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "����������, �� ������� ����. \n���� ��������� �������, ��� ��� �����.\n� �� �� ���� ��� ������� ��� ����.");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "��-������� ���� �� ��� �������. \n �� ����� ���� � ���� ��. \n������? � �� ����� ������:");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "������ �������, ��� � ��� ��� �������. \n �������, ������� ����� �� �� �������. \n���� � ���� ����� ����������.");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "�� �� ��������� ������� ��� �������. \n������, ���� ���� ���������� �� �� ���������. \n������ ��, ��� �����.");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "� �� ��-�� ����, ��� �� ������ ��� ������� \n������, ���� ���� ���������� �� �� �� ���������. \n�������, ��� �����!");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "�� � ���� � ����� ���� ����� - ������. \n� ������� �� ����� ����� � ����� ������. \n� �� ��������� ����.");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "�������, ��� �� ��� ����������. \n� ����� ������ ������� ��������! \n����� ����!");
    }
    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "������� ���� �� ���. \n��� ���� ���� - $$$. \n� ��� ���� ����, �����.");
        txSleep(TIME_IN_FINALLY_MONOLOGUE);
    }

    if (theEnd==CREATION)
    {

    }
    txSleep(1000);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    while (!(txMouseX()>450 and txMouseY()>450 and txMouseX()<550 and txMouseY()<550 and txMouseButtons()==1))
    {
        txSetColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

        if(!(txMouseX()>450 and txMouseY()>450 and txMouseX()<550 and txMouseY()<550))
        {
            drawLetter(false);
        }
        else
        {
            drawLetter(true);
        }

        txSleep(50);
    }

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(500);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "�.�.: ��������� ����� ����� �� ������ ���. \n� ����� ��������� �������� ���� \n����� ��� ����������� ��������.");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "�.�.: ��������� ����� ����� �� ������ ���. \n��� ������� ����������� ���������. \n�� ��� ������ ���������� �������.");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "� ��� ���� ����� �������: \n \"���� ����� ����� - \n �� ������ �����!..");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "������� ���������� ��������, \n ���� ����� ������, \n �� ��� ��������� � ����������.");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);

    txSetColor(TX_WHITE);

    if (theEnd==GREED)
    {
        txDrawText(100, 100, 900, 900, "����� ������, ����� ������, \n � ��������� �� - �����������!\"");
    }

    if (theEnd==CREATION)
    {
        txDrawText(100, 100, 900, 900, "� ������� �� ������ ���������� �����: \n \"�������� ����� ������!\"");
    }

    txSleep(TIME_IN_FINALLY_MONOLOGUE);

    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(1000);
    exit();
}

/**
    1) name - dialogue speaker name
**/
void drawNameFoSpeaker(enum CharacterNames name)
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, 200);
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txSelectFont("Times New Roman", 175, 40);
    txSetTextAlign(TA_LEFT);

    if (name==HERO)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "������� �����:");
    }
    if (name==CARPENTER)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "�������:");
    }
    if (name==ARCHITECT)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "����������:");
    }
    if (name==ENGINEER)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "�������:");
    }
    if (name==LIBRARIAN)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "������������:");
    }
    if (name==QUESTIONNAIRE)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "�������:");
    }
    if (name==MINER)
    {
        txDrawText(MIN_X, MIN_Y, MAX_X, 200, "�����:");
    }

    txSelectFont("Times New Roman", 100, 12);
}

/**
    1) scale - increases or decreases letter
**/
void drawLetter(bool scale)
{
    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK);

    if (!scale)
    {
        txRectangle(460, 460, 540, 540);

        txSetFillColor(TX_BLACK);

        txRectangle(480, 480, 520, 490);
        txRectangle(480, 520, 520, 530);
    }
    else
    {
        txRectangle(450, 450, 550, 550);

        txSetFillColor(TX_BLACK);

        txRectangle(475, 479, 525, 491);
        txRectangle(475, 519, 525, 531);
    }
}

/**
    1) numberColorInFakeMenu - background color advertising
**/
void drawFullAdvertisingBackground(int *numberColorInFakeMenu)
{
    drawAdvertisingBackground(numberColorInFakeMenu);

    drawBoxOfAdvertising(950, 50);
    drawBoxOfAdvertising(450, 250);
    drawBoxOfAdvertising(750, 550);
    drawBoxOfAdvertising(500, 500);
}

/**
    1) numberColorInFakeMenu - background color advertising
**/
void drawAdvertisingBackground(int *numberColorInFakeMenu)
{
    txSleep(50);
    txSetFillColor(TX_WHITE);
    txClear();

    for (int j=0; j<BACKGROUND_OF_ADVERTISING; ++j)
    {
        selectColorInFakeMenu(numberColorInFakeMenu);
        txSelectFont("Comic Sans MS", 120);
        txDrawText(-100-50*j, 10+140*j, 1600-50*j, 10+140*(j+1), "������� ������� ������� ������� ������� ������� ������� ������� ������� ������� �������");
    }

    txSelectFont("Comic Sans MS", 200);
    txSetColor(TX_BLACK);
    txDrawText(100, 100, 900, 900, "�������");
}

/**
    1) x - x coordinate of the button
    2) y - y coordinate of the button
**/
void drawXButtonInFakeGame(int x, int y)
{
    txSetFillColor(TX_RED);

    if (txMouseX()>x and txMouseY()>y and txMouseX()<x+100 and txMouseY()<y+100)
    {
        txSetFillColor(TX_WHITE);
    }

    txRectangle(x, y, x+100, y+100);
    txSelectFont("Comic Sans MS", 90);
    txDrawText(x, y, x+100, y+100, "X");
}

/**
    1) x - x coordinate of the box
    2) y - y coordinate of the box
**/
void drawBoxOfAdvertising(int x, int y)
{
    txSetColor(TX_BLACK);
    txSelectFont("Comic Sans MS", 55, 13);

    for (int i=0; i<QUANTITY_WORDS_IN_BOX_OF_ADVERTISING; ++i)
    {
        txDrawText(x-150, y-150+60*i, x+150, y-90+60*i, "������� �������");
    }
}

/**
    1) x - x coordinate of the object
    2) y - y coordinate of the object
    3) type - type of object
**/
void drawObjectInFakeGame(int x, int y, enum TypeOfLet type)
{
    if (type==OBJECT_ROCK)
    {
       for (int i=0; i<ROCKS_ON_X; ++i)
       {
            for (int j=0; j<ROCKS_ON_Y; ++j)
            {
                drawRock(x+20*i, y+40*j);
            }
       }
    }

    if (type==OBJECT_FENCE)
    {
        drawFenceBoard(x, y, x+5, y+200);

        for (int i=0; i<OBJECT; ++i)
        {
            drawFence(x, y+50*i, 0);
        }
    }

    if (type==OBJECT_PUDDLE)
    {
        drawPuddle(x, y, x+200, y+200);

        drawWave(x+50, y+50);
        drawWave(x+100, y+10);
        drawWave(x+170, y+150);
        drawWave(x+40, y+140);
        drawWave(x+70, y+90);
    }

    if (type==OBJECT_VOID)
    {
        txSetFillColor(TX_BLACK);
        txSetColor(TX_BLACK);

        txRectangle(x, y, x+200, y+200);
    }
}

/**
    1) firstBugInGame - error check with dialog arrows
    3) normalGame - game type check
**/
void drawSelectInContract(bool *firstBugInGame, bool *normalGame)
{
    bool outOfTheSelect = false;

    while (!outOfTheSelect)
        {
            txSetColor(TX_BLACK);
            txSelectFont("Times New Roman", 100, 12);

            txSetFillColor(TX_GREEN);
            if (txMouseX()>900 and txMouseY()>800 and txMouseY()<900)
            {
                txSetFillColor(TX_WHITE);
            }
            txRectangle(900, 800, MAX_X, 900);
            txDrawText(900, 800, MAX_X, 900, "��");

            txSetFillColor(TX_RED);
            if (txMouseX()>900 and txMouseY()>900 and txMouseY()<MAX_Y)
            {
                txSetFillColor(TX_WHITE);
            }
            txRectangle(900, 900, MAX_X, MAX_Y);
            txDrawText(900, 900, MAX_X, MAX_Y, "���");

            if (txMouseX()>900 and txMouseY()>800 and txMouseY()<900 and txMouseButtons()==1)
            {
                outOfTheSelect = true;
                drawGameDialog(HERO_AGRESS_TO_ADVERTISING_CONTRACT, firstBugInGame, normalGame);
                *normalGame = false;
            }

            if (txMouseX()>900 and txMouseY()>900 and txMouseY()<MAX_Y and txMouseButtons()==1)
            {
                outOfTheSelect = true;
                drawGameDialog(HERO_REFUSES_ADVERTISING_CONTRACT, firstBugInGame, normalGame);
            }

            txSleep(50);
        }
}

/**
    1) x - x coordinate of the arrow
    2) y - y coordinate of the arrow
**/
void drawArrow(int x, int y)
{
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    POINT arrow[3] = {{x, y}, {x, y+40}, {x+20, y+20}};
    txPolygon(arrow, 3);
}

/**
    1) x - x coordinate of the box
    2) y - y coordinate of the box
**/
void drawArrowsInDialog(bool *firstBugInGame, bool *normalGame)
{
    int x = 920;
    int changeX = SPEED_ARROWS_IN_DIALOG;
    bool normalArrows = true;
    bool pressSpace = true;
    COLORREF colorError = RGB(193, 0, 255);
    while(!GetAsyncKeyState(VK_SPACE) and pressSpace)
    {
        if (normalArrows)
        {
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txRectangle(900, 800, MAX_X, MAX_Y);

            drawArrow(x, 820);
            drawArrow(x, 880);
            drawArrow(x, 940);

            x = x+changeX;

            if (x>=965)
            {
                changeX = -SPEED_ARROWS_IN_DIALOG;
            }

            if (x<=920)
            {
                changeX = SPEED_ARROWS_IN_DIALOG;
            }

            if (txMouseX()>900 and txMouseY()>800 and txMouseButtons()==1 and *normalGame)
            {
                normalArrows = false;
            }
        }

        if (!normalArrows)
        {
            while(!GetAsyncKeyState(VK_SPACE) and pressSpace)
            {
                txSetFillColor(colorError);
                txSetColor(colorError);
                txRectangle(MIN_X, 800, MAX_X, MAX_Y);
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txDrawText(MIN_X, 800, MAX_X, MAX_Y, "ERRORERRORERRORERRORERRORERRORERRORERRORERRORERRORERRORERROR\nERRORERRORERRORERRORERRORERRORERRORERRORERROR");
                txSleep(50);
            }
            txSleep(TIME_FOR_PRESS_SPACE);

            if (*firstBugInGame)
            {
                txSetFillColor(TX_BLACK);
                txSetColor(TX_BLACK);
                txRectangle(MIN_X, 800, MAX_X, MAX_Y);
                *firstBugInGame = false;
                txSetFillColor(TX_WHITE);
                txSetColor(TX_WHITE);
                txSelectFont("Times New Roman", 100, 12);
                txTextOut(X_FOR_TEXT, BOTTOM_Y_FOR_TEXT, "- ��, ��� ������! �� ����, ��� ���� ����� �������!");
                txTextOut(X_FOR_TEXT, TOP_Y_FOR_TEXT, "����� ������ ���� �� �������.");
                normalArrows = true;
                while(!GetAsyncKeyState(VK_SPACE))
                {}
            }

            pressSpace = false;
        }
        txSleep(50);
    }

    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, 800, MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txSelectFont("Times New Roman", 100, 12);
    txSleep(TIME_FOR_PRESS_SPACE);
}

/**
    1) acceleration - acceleration of hero
**/
void pressShift(int *acceleration)
{
    if (GetAsyncKeyState(VK_SHIFT))
        {
            *acceleration = 3;
        }
        else
        {
            *acceleration = 1;
        }
}

/**
    1) numberColorInFakeMenu - background color advertising
**/
void selectColorInFakeMenu(int *numberColorInFakeMenu)
{
    if (*numberColorInFakeMenu == 70)
    {
        *numberColorInFakeMenu = 1;
    }

    if (*numberColorInFakeMenu/10 == RED)
    {
        txSetColor(TX_RED);
    }

    if (*numberColorInFakeMenu/10 == ORANGE)
    {
        txSetColor(TX_ORANGE);
    }

    if (*numberColorInFakeMenu/10 == YELLOW)
    {
        txSetColor(TX_YELLOW);
    }

    if (*numberColorInFakeMenu/10 == GREEN)
    {
        txSetColor(TX_GREEN);
    }

    if (*numberColorInFakeMenu/10 == LIGHT_BLUE)
    {
        txSetColor(TX_LIGHTBLUE);
    }

    if (*numberColorInFakeMenu/10 == BLUE)
    {
        txSetColor(TX_BLUE);
    }

    if (*numberColorInFakeMenu/10 == PURPLE)
    {
        txSetColor(TX_MAGENTA);
    }

    *numberColorInFakeMenu += 1;
}

/**
    1) xHero - x coordinate of the hero to determine the visible part of the map
    2) yHero - y coordinate of the hero to determine the visible part of the map
    3) positionGrafic - hero position to determine the visible part of the map
**/
void selectPositionGrafic(int xHero, int yHero, int *positionGrafic)
{
    if (xHero>800 and xHero<1000 and yHero>400 and yHero<550)
    {
        *positionGrafic=0;
    }

    if (xHero>400 and xHero<600 and yHero>750 and yHero<950)
    {
        *positionGrafic=1;
    }

    if (xHero>800 and xHero<1000 and yHero>750 and yHero<950)
    {
        *positionGrafic=2;
    }

    if (xHero>600 and xHero<1000 and yHero>200 and yHero<400)
    {
        *positionGrafic=3;
    }

    if (xHero>600 and xHero<800 and yHero>400 and yHero<550)
    {
        *positionGrafic=4;
    }

    if (xHero>600 and xHero<800 and yHero>550 and yHero<750)
    {
        *positionGrafic=5;
    }

    if (xHero>0 and xHero<200 and yHero>550 and yHero<750)
    {
        *positionGrafic=6;
    }

    if (xHero>0 and xHero<200 and yHero>0 and yHero<200)
    {
        *positionGrafic=7;
    }

    if (xHero>400 and xHero<600 and yHero>0 and yHero<200)
    {
        *positionGrafic=8;
    }
}

/**
    1) xHero - x coordinate for hero teleportation
    2) yHero - y coordinate for hero teleportation
    3) heroInPuddle - check for a hero in a puddle so that teleportation does not occur
    4) portal - number of portal
**/
void selectionPortalInStory(int *xHero, int *yHero, bool heroInPuddle, int portal)
{
    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK);
    txRectangle(400, 420, 600, 530);
    txSelectFont("Comic Sans MS", 40, 15);
    txDrawText(410, 430, 590, 520, "������� \n������");
    if (GetAsyncKeyState(VK_SPACE) and !heroInPuddle)
        {
            txSleep(250);
            if (portal==1)
            {
                *xHero = 350;
                *yHero = 900;
            }
            if (portal==2)
            {
                *xHero = 100;
                *yHero = 100;
            }
            if (portal==3)
            {
                *xHero = 900;
                *yHero = 100;
            }
            if (portal==4)
            {
                *xHero = 500;
                *yHero = 650;
            }
            if (portal==5)
            {
                *xHero = 650;
                *yHero = 900;
            }
            if (portal==6)
            {
                *xHero = 500;
                *yHero = 300;
            }
            if (portal==7)
            {
                *xHero = 100;
                *yHero = 650;
            }
            if (portal==8)
            {
                *xHero = 900;
                *yHero = 650;
            }
            if (portal==9)
            {
                *xHero = 900;
                *yHero = 400;
            }
        }
}

/**
    1) x - x coordinate of hero
    2) y - y coordinate of hero
    3) heroInPuddle - check for a hero in a puddle
**/
void drawHeroWithoutGrafics(int x, int y, bool heroInPuddle)
{
    int scale;

    if (heroInPuddle)
    {
        scale = 10;
    }
    else
    {
        scale = 0;
    }

    txSetColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    txSelectFont("Comic Sans MS", 30, 10);
    txRectangle(x-75+scale, y-75+scale, x+75-scale, y+75-scale);
    txDrawText(x-50, y-30, x+50, y+30, "������� \n�����");
}

/**
    1) x - x coordinate of hero
    2) y - y coordinate of hero
    3) heroInPuddle - check for a hero in a puddle
    4) direction - direction of hero
**/
void drawHeroWithGrafics(int x, int y, bool heroInPuddle, enum DirectionHero direction)
{
    double scale;

    if (heroInPuddle)
    {
        scale = 1.2;
    }
    else
    {
        scale = 1;
    }
    COLORREF mainColorCap = RGB(46, 150, 228);
    COLORREF lightShadowColorCap = RGB(18, 121, 199);
    COLORREF darkShadowColorCap = RGB(0, 76, 171);
    COLORREF colorButtonCap = RGB(250, 225, 11);
    COLORREF colorLogoCap = RGB(241, 127, 0);
    if (direction==DOWN)
    {
        POINT bodyCap [41] = {{x-10/scale, y-75/scale}, {x-15/scale, y-73/scale}, {x-20/scale, y-70/scale}, {x-25/scale, y-66/scale}, {x-30/scale, y-61/scale},
        {x-35/scale, y-55/scale}, {x-38/scale, y-50/scale}, {x-40/scale, y-45/scale}, {x-44/scale, y-40/scale}, {x-45/scale, y-35/scale},
        {x-47/scale, y-32/scale}, {x-47/scale, y-15/scale}, {x-46/scale, y-5/scale}, {x-45/scale, y+5/scale}, {x-43/scale, y+15/scale},
        {x-41/scale, y+23/scale}, {x-39/scale, y+29/scale}, {x-34/scale, y+35/scale}, {x-25/scale, y+41/scale}, {x-15/scale, y+45/scale},
        {x-5/scale, y+45/scale}, {x+5/scale, y+43/scale}, {x+15/scale, y+39/scale}, {x+23/scale, y+35/scale}, {x+25/scale, y+31/scale},
        {x+28/scale, y+29/scale}, {x+30/scale, y+25/scale}, {x+32/scale, y+21/scale}, {x+35/scale, y+16/scale}, {x+40/scale, y+5/scale},
        {x+43/scale, y-5/scale}, {x+45/scale, y-15/scale}, {x+48/scale, y-25/scale}, {x+47/scale, y-35/scale}, {x+45/scale, y-43/scale},
        {x+41/scale, y-55/scale}, {x+38/scale, y-62/scale}, {x+32/scale, y-71/scale}, {x+25/scale, y-75/scale}, {x+23/scale, y-75/scale},
        {x-10/scale, y-75/scale}};
        POINT visorCap [16] = {{x-39/scale, y+29/scale}, {x-39/scale, y+35/scale}, {x-37/scale, y+45/scale}, {x-35/scale, y+50/scale}, {x-25/scale, y+66/scale},
        {x-20/scale, y+71/scale}, {x-10/scale, y+75/scale}, {x+3/scale, y+75/scale}, {x+15/scale, y+69/scale}, {x+20/scale, y+65/scale},
        {x+29/scale, y+55/scale}, {x+32/scale, y+45/scale}, {x+34/scale, y+35/scale}, {x+33/scale, y+25/scale}, {x+32/scale, y+21/scale},
        {x-39/scale, y+29/scale}};
        POINT leftShadowMainCap [22] = {{x-35/scale, y-55/scale}, {x-38/scale, y-50/scale}, {x-40/scale, y-45/scale}, {x-44/scale, y-40/scale}, {x-45/scale, y-35/scale},
        {x-47/scale, y-32/scale}, {x-47/scale, y-15/scale}, {x-46/scale, y-5/scale}, {x-45/scale, y+5/scale}, {x-43/scale, y+15/scale},
        {x-41/scale, y+23/scale}, {x-35/scale, y+26/scale}, {x-30/scale, y+28/scale}, {x-34/scale, y+15/scale}, {x-35/scale, y+5/scale},
        {x-35/scale, y-25/scale}, {x-34/scale, y-35/scale}, {x-31/scale, y-45/scale}, {x-27/scale, y-55/scale}, {x-25/scale, y-58/scale},
        {x-32/scale, y-56/scale}, {x-35/scale, y-55/scale}};
        POINT upShadowMainCap [18] = {{x+25/scale, y-72/scale}, {x+23/scale, y-75/scale}, {x-10/scale, y-75/scale}, {x-15/scale, y-73/scale}, {x-20/scale, y-70/scale},
        {x-25/scale, y-66/scale}, {x-30/scale, y-61/scale}, {x-35/scale, y-55/scale}, {x-32/scale, y-56/scale}, {x-25/scale, y-58/scale},
        {x-15/scale, y-62/scale}, {x-5/scale, y-64/scale}, {x+5/scale, y-63/scale}, {x+15/scale, y-60/scale}, {x+25/scale, y-57/scale},
        {x+32/scale, y-55/scale}, {x+30/scale, y-65/scale}, {x+25/scale, y-72/scale}};
        POINT downShadowMainCap [20] = {{x-41/scale, y+23/scale}, {x-39/scale, y+29/scale}, {x-34/scale, y+35/scale}, {x-25/scale, y+41/scale}, {x-15/scale, y+43/scale},
        {x-5/scale, y+43/scale}, {x+5/scale, y+42/scale}, {x+15/scale, y+39/scale}, {x+23/scale, y+35/scale}, {x+25/scale, y+31/scale},
        {x+27/scale, y+23/scale}, {x+20/scale, y+28/scale}, {x+15/scale, y+29/scale}, {x+5/scale, y+30/scale}, {x-5/scale, y+31/scale},
        {x-7/scale, y+31/scale}, {x-25/scale, y+29/scale}, {x-30/scale, y+28/scale}, {x-35/scale, y+26/scale}, {x-41/scale, y+23/scale}};
        POINT rightShadowVisorCap [10] = {{x+20/scale, y+65/scale}, {x+29/scale, y+55/scale}, {x+32/scale, y+45/scale}, {x+34/scale, y+35/scale}, {x+33/scale, y+25/scale},
        {x+32/scale, y+21/scale}, {x+30/scale, y+25/scale}, {x+28/scale, y+29/scale}, {x+28/scale, y+45/scale}, {x+20/scale, y+65/scale}};
        POINT rightShadowMainCap [26] = {{x+23/scale, y+35/scale}, {x+28/scale, y+29/scale}, {x+30/scale, y+25/scale}, {x+32/scale, y+21/scale}, {x+35/scale, y+16/scale},
        {x+40/scale, y+5/scale}, {x+43/scale, y-5/scale}, {x+45/scale, y-15/scale}, {x+48/scale, y-25/scale}, {x+47/scale, y-35/scale},
        {x+45/scale, y-43/scale}, {x+41/scale, y-55/scale}, {x+38/scale, y-62/scale}, {x+32/scale, y-71/scale},{x+25/scale, y-75/scale},
        {x+30/scale, y-65/scale}, {x+32/scale, y-55/scale}, {x+35/scale, y-45/scale}, {x+36/scale, y-25/scale}, {x+36/scale, y-15/scale},
        {x+34/scale, y-5/scale}, {x+32/scale, y+5/scale}, {x+30/scale, y+15/scale}, {x+27/scale, y+23/scale}, {x+25/scale, y+31/scale},
        {x+23/scale, y+35/scale}};

        POINT symbolI [13] = {{x-13/scale, y+46/scale}, {x-5/scale, y+46/scale}, {x-5/scale, y+48/scale}, {x-8/scale, y+48/scale}, {x-8/scale, y+52/scale},
        {x-5/scale, y+52/scale}, {x-5/scale, y+54/scale}, {x-13/scale, y+54/scale}, {x-13/scale, y+52/scale}, {x-10/scale, y+52/scale},
        {x-10/scale, y+48/scale}, {x-13/scale, y+48/scale}, {x-13/scale, y+46/scale}};
        POINT symbolT [9] = {{x-3/scale, y+46/scale}, {x+5/scale, y+46/scale}, {x+5/scale, y+48/scale}, {x+2/scale, y+48/scale}, {x+2/scale, y+54/scale},
        {x+0/scale, y+54/scale}, {x+0/scale, y+48/scale}, {x-3/scale, y+48/scale}, {x-3/scale, y+46/scale}};
        POINT symbolSH [13] = {{x-26/scale, y+56/scale}, {x-26/scale, y+64/scale}, {x-18/scale, y+64/scale}, {x-18/scale, y+56/scale}, {x-20/scale, y+56/scale},
        {x-20/scale, y+62/scale}, {x-21/scale, y+62/scale}, {x-21/scale, y+56/scale}, {x-23/scale, y+56/scale}, {x-23/scale, y+62/scale},
        {x-24/scale, y+62/scale}, {x-24/scale, y+56/scale}, {x-26/scale, y+56/scale}};
        POINT symbolK [14] = {{x-16/scale, y+56/scale}, {x-16/scale, y+64/scale}, {x-13/scale, y+64/scale}, {x-13/scale, y+62/scale}, {x-11/scale, y+64/scale},
        {x-8/scale, y+64/scale}, {x-9/scale, y+64/scale}, {x-13/scale, y+60/scale}, {x-8/scale, y+57/scale}, {x-8/scale, y+56/scale},
        {x-10/scale, y+56/scale}, {x-13/scale, y+58/scale}, {x-13/scale, y+56/scale}, {x-16/scale, y+56/scale}};
        POINT symbolO [9] = {{x-5/scale, y+56/scale}, {x-8/scale, y+59/scale}, {x-8/scale, y+61/scale}, {x-5/scale, y+64/scale}, {x-3/scale, y+64/scale},
        {x+0/scale, y+61/scale}, {x+0/scale, y+59/scale}, {x-3/scale, y+56/scale}, {x-5/scale, y+56/scale}};
        POINT voidSymbolO [9] = {{x-5/scale, y+58/scale}, {x-6/scale, y+57/scale}, {x-6/scale, y+61/scale}, {x-5/scale, y+62/scale}, {x-3/scale, y+62/scale},
        {x-2/scale, y+61/scale}, {x-2/scale, y+59/scale}, {x-3/scale, y+58/scale}, {x-5/scale, y+58/scale}};
        POINT symbolL [9] = {{x+4/scale, y+56/scale}, {x+1/scale, y+64/scale}, {x+3/scale, y+64/scale}, {x+4.2/scale, y+58/scale}, {x+5.8/scale, y+58/scale},
        {x+7/scale, y+64/scale}, {x+9/scale, y+64/scale}, {x+6/scale, y+56/scale}, {x+4/scale, y+56/scale}};
        POINT symbolA [9] = {{x+13/scale, y+56/scale}, {x+10/scale, y+64/scale}, {x+8/scale, y+64/scale}, {x+12.6/scale, y+61/scale}, {x+15.4/scale, y+61/scale},
        {x+16/scale, y+64/scale}, {x+18/scale, y+64/scale}, {x+15/scale, y+56/scale}, {x+13/scale, y+56/scale}};
        POINT voidSymbolA [5] = {{x+13.2/scale, y+58/scale}, {x+12.8/scale, y+60/scale}, {x+15.2/scale, y+60/scale}, {x+14.8/scale, y+58/scale}, {x+13.2/scale, y+58/scale}};

        txSetFillColor(mainColorCap);
        txSetColor(mainColorCap);
        txPolygon(bodyCap, 41);
        txPolygon(visorCap, 16);
        txSetFillColor(lightShadowColorCap);
        txSetColor(lightShadowColorCap);
        txPolygon(leftShadowMainCap, 22);
        txPolygon(upShadowMainCap, 18);
        txPolygon(downShadowMainCap, 20);
        txPolygon(rightShadowVisorCap, 10);
        txSetFillColor(darkShadowColorCap);
        txSetColor(darkShadowColorCap);
        txPolygon(rightShadowMainCap, 26);

        txSetFillColor(colorButtonCap);
        txSetColor(TX_BLACK);
        txCircle(x+0/scale, y-20/scale, 5/scale);
        txSetFillColor(colorLogoCap);
        txPolygon(symbolI, 13);
        txPolygon(symbolT, 9);
        txPolygon(symbolSH, 13);
        txPolygon(symbolK, 14);
        txPolygon(symbolO, 9);
        txPolygon(symbolL, 9);
        txPolygon(symbolA, 9);
        txSetFillColor(mainColorCap);
        txPolygon(voidSymbolO, 9);
        txPolygon(voidSymbolA, 5);
    }
    if (direction==RIGHT)
    {
        POINT bodyCap [41] = {{x-75/scale, y+10/scale}, {x-73/scale, y+15/scale}, {x-70/scale, y+20/scale}, {x-66/scale, y+25/scale}, {x-61/scale, y+30/scale},
        {x-55/scale, y+35/scale}, {x-50/scale, y+38/scale}, {x-45/scale, y+40/scale}, {x-40/scale, y+44/scale}, {x-35/scale, y+45/scale},
        {x-32/scale, y+47/scale}, {x-15/scale, y+47/scale}, {x-5/scale, y+46/scale}, {x+5/scale, y+45/scale}, {x+15/scale, y+43/scale},
        {x+23/scale, y+41/scale}, {x+29/scale, y+39/scale}, {x+35/scale, y+34/scale}, {x+41/scale, y+25/scale}, {x+45/scale, y+15/scale},
        {x+45/scale, y+5/scale}, {x+43/scale, y-5/scale}, {x+39/scale, y-15/scale}, {x+35/scale, y-23/scale}, {x+31/scale, y-25/scale},
        {x+29/scale, y-28/scale}, {x+25/scale, y-30/scale}, {x+21/scale, y-32/scale}, {x+16/scale, y-35/scale}, {x+5/scale, y-40/scale},
        {x-5/scale, y-43/scale}, {x-15/scale, y-45/scale}, {x-25/scale, y-48/scale}, {x-35/scale, y-47/scale}, {x-43/scale, y-45/scale},
        {x-55/scale, y-41/scale}, {x-62/scale, y-38/scale}, {x-71/scale, y-32/scale}, {x-75/scale, y-25/scale}, {x-75/scale, y-23/scale},
        {x-75/scale, y+10/scale}};
        POINT visorCap [16] = {{x+29/scale, y+39/scale}, {x+35/scale, y+39/scale}, {x+45/scale, y+37/scale}, {x+50/scale, y+35/scale}, {x+66/scale, y+25/scale},
        {x+71/scale, y+20/scale}, {x+75/scale, y+10/scale}, {x+75/scale, y-3/scale}, {x+69/scale, y-15/scale}, {x+65/scale, y-20/scale},
        {x+55/scale, y-29/scale}, {x+45/scale, y-32/scale}, {x+35/scale, y-34/scale}, {x+25/scale, y-33/scale}, {x+21/scale, y-32/scale},
        {x+29/scale, y+39/scale}};
        POINT downShadowMainCap [22] = {{x-55/scale, y+35/scale}, {x-50/scale, y+38/scale}, {x-45/scale, y+40/scale}, {x-40/scale, y+44/scale}, {x-35/scale, y+45/scale},
        {x-32/scale, y+47/scale}, {x-15/scale, y+47/scale}, {x-5/scale, y+46/scale}, {x+5/scale, y+45/scale}, {x+15/scale, y+43/scale},
        {x+23/scale, y+41/scale}, {x+26/scale, y+35/scale}, {x+28/scale, y+30/scale}, {x+15/scale, y+34/scale}, {x+5/scale, y+35/scale},
        {x-25/scale, y+35/scale}, {x-35/scale, y+34/scale}, {x-45/scale, y+31/scale}, {x-55/scale, y+27/scale}, {x-58/scale, y+25/scale},
        {x-56/scale, y+32/scale}, {x-55/scale, y+35/scale}};
        POINT leftShadowMainCap [18] = {{x-72/scale, y-25/scale}, {x-75/scale, y-23/scale}, {x-75/scale, y+10/scale}, {x-73/scale, y+15/scale}, {x-70/scale, y+20/scale},
        {x-66/scale, y+25/scale}, {x-61/scale, y+30/scale}, {x-55/scale, y+35/scale}, {x-56/scale, y+32/scale}, {x-58/scale, y+25/scale},
        {x-62/scale, y+15/scale}, {x-64/scale, y+5/scale}, {x-63/scale, y-5/scale}, {x-60/scale, y-15/scale}, {x-57/scale, y-25/scale},
        {x-55/scale, y-32/scale}, {x-65/scale, y-30/scale}, {x-72/scale, y-25/scale}};
        POINT rightShadowMainCap [20] = {{x+23/scale, y+41/scale}, {x+29/scale, y+39/scale}, {x+35/scale, y+34/scale}, {x+41/scale, y+25/scale}, {x+43/scale, y+15/scale},
        {x+43/scale, y+5/scale}, {x+42/scale, y-5/scale}, {x+39/scale, y-15/scale}, {x+35/scale, y-23/scale}, {x+31/scale, y-25/scale},
        {x+23/scale, y-27/scale}, {x+28/scale, y-20/scale}, {x+29/scale, y-15/scale}, {x+30/scale, y-5/scale}, {x+31/scale, y+5/scale},
        {x+31/scale, y+7/scale}, {x+29/scale, y+25/scale}, {x+28/scale, y+30/scale}, {x+26/scale, y+35/scale}, {x+23/scale, y+41/scale}};
        POINT upShadowVisorCap [10] = {{x+65/scale, y-20/scale}, {x+55/scale, y-29/scale}, {x+45/scale, y-32/scale}, {x+35/scale, y-34/scale}, {x+25/scale, y-33/scale},
        {x+21/scale, y-32/scale}, {x+25/scale, y-30/scale}, {x+29/scale, y-28/scale}, {x+45/scale, y-28/scale}, {x+65/scale, y-20/scale}};
        POINT upShadowMainCap [26] = {{x+35/scale, y-23/scale}, {x+29/scale, y-28/scale}, {x+25/scale, y-30/scale}, {x+21/scale, y-32/scale}, {x+16/scale, y-35/scale},
        {x+5/scale, y-40/scale}, {x-5/scale, y-43/scale}, {x-15/scale, y-45/scale}, {x-25/scale, y-48/scale}, {x-35/scale, y-47/scale},
        {x-43/scale, y-45/scale}, {x-55/scale, y-41/scale}, {x-62/scale, y-38/scale}, {x-71/scale, y-32/scale},{x-75/scale, y-25/scale},
        {x-65/scale, y-30/scale}, {x-55/scale, y-32/scale}, {x-45/scale, y-35/scale}, {x-25/scale, y-36/scale}, {x-15/scale, y-36/scale},
        {x-5/scale, y-34/scale}, {x+5/scale, y-32/scale}, {x+15/scale, y-30/scale}, {x+23/scale, y-27/scale}, {x+31/scale, y-25/scale},
        {x+35/scale, y-23/scale}};

        POINT symbolI [13] = {{x+46/scale, y+13/scale}, {x+46/scale, y+5/scale}, {x+48/scale, y+5/scale}, {x+48/scale, y+8/scale}, {x+52/scale, y+8/scale},
        {x+52/scale, y+5/scale}, {x+54/scale, y+5/scale}, {x+54/scale, y+13/scale}, {x+52/scale, y+13/scale}, {x+52/scale, y+10/scale},
        {x+48/scale, y+10/scale}, {x+48/scale, y+13/scale}, {x+46/scale, y+13/scale}};
        POINT symbolT [9] = {{x+46/scale, y+3/scale}, {x+46/scale, y-5/scale}, {x+48/scale, y-5/scale}, {x+48/scale, y-2/scale}, {x+54/scale, y-2/scale},
        {x+54/scale, y-0/scale}, {x+48/scale, y-0/scale}, {x+48/scale, y+3/scale}, {x+46/scale, y+3/scale}};
        POINT symbolSH [13] = {{x+56/scale, y+26/scale}, {x+64/scale, y+26/scale}, {x+64/scale, y+18/scale}, {x+56/scale, y+18/scale}, {x+56/scale, y+20/scale},
        {x+62/scale, y+20/scale}, {x+62/scale, y+21/scale}, {x+56/scale, y+21/scale}, {x+56/scale, y+23/scale}, {x+62/scale, y+23/scale},
        {x+62/scale, y+24/scale}, {x+56/scale, y+24/scale}, {x+56/scale, y+26/scale}};
        POINT symbolK [14] = {{x+56/scale, y+16/scale}, {x+64/scale, y+16/scale}, {x+64/scale, y+13/scale}, {x+62/scale, y+13/scale}, {x+64/scale, y+11/scale},
        {x+64/scale, y+8/scale}, {x+64/scale, y+9/scale}, {x+60/scale, y+13/scale}, {x+57/scale, y+8/scale}, {x+56/scale, y+8/scale},
        {x+56/scale, y+10/scale}, {x+58/scale, y+13/scale}, {x+56/scale, y+13/scale}, {x+56/scale, y+16/scale}};
        POINT symbolO [9] = {{x+56/scale, y+5/scale}, {x+59/scale, y+8/scale}, {x+61/scale, y+8/scale}, {x+64/scale, y+5/scale}, {x+64/scale, y+3/scale},
        {x+61/scale, y-0/scale}, {x+59/scale, y-0/scale}, {x+56/scale, y+3/scale}, {x+56/scale, y+5/scale}};
        POINT voidSymbolO [9] = {{x+58/scale, y+5/scale}, {x+57/scale, y+6/scale}, {x+61/scale, y+6/scale}, {x+62/scale, y+5/scale}, {x+62/scale, y+3/scale},
        {x+61/scale, y+2/scale}, {x+59/scale, y+2/scale}, {x+58/scale, y+3/scale}, {x+58/scale, y+5/scale}};
        POINT symbolL [9] = {{x+56/scale, y-4/scale}, {x+64/scale, y-1/scale}, {x+64/scale, y-3/scale}, {x+58/scale, y-4.2/scale}, {x+58/scale, y-5.8/scale},
        {x+64/scale, y-7/scale}, {x+64/scale, y-9/scale}, {x+56/scale, y-6/scale}, {x+56/scale, y-4/scale}};
        POINT symbolA [9] = {{x+56/scale, y-13/scale}, {x+64/scale, y-10/scale}, {x+64/scale, y-8/scale}, {x+61/scale, y-12.6/scale}, {x+61/scale, y-15.4/scale},
        {x+64/scale, y-16/scale}, {x+64/scale, y-18/scale}, {x+56/scale, y-15/scale}, {x+56/scale, y-13/scale}};
        POINT voidSymbolA [5] = {{x+58/scale, y-13.2/scale}, {x+60/scale, y-12.8/scale}, {x+60/scale, y-15.2/scale}, {x+58/scale, y-14.8/scale}, {x+58/scale, y-13.2/scale}};

        txSetFillColor(mainColorCap);
        txSetColor(mainColorCap);
        txPolygon(bodyCap, 41);
        txPolygon(visorCap, 16);
        txSetFillColor(lightShadowColorCap);
        txSetColor(lightShadowColorCap);
        txPolygon(downShadowMainCap, 22);
        txPolygon(leftShadowMainCap, 18);
        txPolygon(upShadowMainCap, 26);
        txPolygon(upShadowVisorCap, 10);
        txSetFillColor(darkShadowColorCap);
        txSetColor(darkShadowColorCap);
        txPolygon(rightShadowMainCap, 20);

        txSetFillColor(colorButtonCap);
        txSetColor(TX_BLACK);
        txCircle(x-20/scale, y+0/scale, 5/scale);
        txSetFillColor(colorLogoCap);
        txPolygon(symbolI, 13);
        txPolygon(symbolT, 9);
        txPolygon(symbolSH, 13);
        txPolygon(symbolK, 14);
        txPolygon(symbolO, 9);
        txPolygon(symbolL, 9);
        txPolygon(symbolA, 9);
        txSetFillColor(mainColorCap);
        txPolygon(voidSymbolO, 9);
        txPolygon(voidSymbolA, 5);
    }
    if (direction==UP)
    {
        POINT bodyCap [41] = {{x+10/scale, y+75/scale}, {x+15/scale, y+73/scale}, {x+20/scale, y+70/scale}, {x+25/scale, y+66/scale}, {x+30/scale, y+61/scale},
        {x+35/scale, y+55/scale}, {x+38/scale, y+50/scale}, {x+40/scale, y+45/scale}, {x+44/scale, y+40/scale}, {x+45/scale, y+35/scale},
        {x+47/scale, y+32/scale}, {x+47/scale, y+15/scale}, {x+46/scale, y+5/scale}, {x+45/scale, y-5/scale}, {x+43/scale, y-15/scale},
        {x+41/scale, y-23/scale}, {x+39/scale, y-29/scale}, {x+34/scale, y-35/scale}, {x+25/scale, y-41/scale}, {x+15/scale, y-45/scale},
        {x+5/scale, y-45/scale}, {x-5/scale, y-43/scale}, {x-15/scale, y-39/scale}, {x-23/scale, y-35/scale}, {x-25/scale, y-31/scale},
        {x-28/scale, y-29/scale}, {x-30/scale, y-25/scale}, {x-32/scale, y-21/scale}, {x-35/scale, y-16/scale}, {x-40/scale, y-5/scale},
        {x-43/scale, y+5/scale}, {x-45/scale, y+15/scale}, {x-48/scale, y+25/scale}, {x-47/scale, y+35/scale}, {x-45/scale, y+43/scale},
        {x-41/scale, y+55/scale}, {x-38/scale, y+62/scale}, {x-32/scale, y+71/scale}, {x-25/scale, y+75/scale}, {x-23/scale, y+75/scale},
        {x+10/scale, y+75/scale}};
        POINT visorCap [16] = {{x+39/scale, y-29/scale}, {x+39/scale, y-35/scale}, {x+37/scale, y-45/scale}, {x+35/scale, y-50/scale}, {x+25/scale, y-66/scale},
        {x+20/scale, y-71/scale}, {x+10/scale, y-75/scale}, {x-3/scale, y-75/scale}, {x-15/scale, y-69/scale}, {x-20/scale, y-65/scale},
        {x-29/scale, y-55/scale}, {x-32/scale, y-45/scale}, {x-34/scale, y-35/scale}, {x-33/scale, y-25/scale}, {x-32/scale, y-21/scale},
        {x+39/scale, y-29/scale}};
        POINT rightShadowMainCap [22] = {{x+35/scale, y+55/scale}, {x+38/scale, y+50/scale}, {x+40/scale, y+45/scale}, {x+44/scale, y+40/scale}, {x+45/scale, y+35/scale},
        {x+47/scale, y+32/scale}, {x+47/scale, y+15/scale}, {x+46/scale, y+5/scale}, {x+45/scale, y-5/scale}, {x+43/scale, y-15/scale},
        {x+41/scale, y-23/scale}, {x+35/scale, y-26/scale}, {x+30/scale, y-28/scale}, {x+34/scale, y-15/scale}, {x+35/scale, y-5/scale},
        {x+35/scale, y+25/scale}, {x+34/scale, y+35/scale}, {x+31/scale, y+45/scale}, {x+27/scale, y+55/scale}, {x+25/scale, y+58/scale},
        {x+32/scale, y+56/scale}, {x+35/scale, y+55/scale}};
        POINT downShadowMainCap [18] = {{x-25/scale, y+72/scale}, {x-23/scale, y+75/scale}, {x+10/scale, y+75/scale}, {x+15/scale, y+73/scale}, {x+20/scale, y+70/scale},
        {x+25/scale, y+66/scale}, {x+30/scale, y+61/scale}, {x+35/scale, y+55/scale}, {x+32/scale, y+56/scale}, {x+25/scale, y+58/scale},
        {x+15/scale, y+62/scale}, {x+5/scale, y+64/scale}, {x-5/scale, y+63/scale}, {x-15/scale, y+60/scale}, {x-25/scale, y+57/scale},
        {x-32/scale, y+55/scale}, {x-30/scale, y+65/scale}, {x-25/scale, y+72/scale}};
        POINT upShadowMainCap [20] = {{x+41/scale, y-23/scale}, {x+39/scale, y-29/scale}, {x+34/scale, y-35/scale}, {x+25/scale, y-41/scale}, {x+15/scale, y-43/scale},
        {x+5/scale, y-43/scale}, {x-5/scale, y-42/scale}, {x-15/scale, y-39/scale}, {x-23/scale, y-35/scale}, {x-25/scale, y-31/scale},
        {x-27/scale, y-23/scale}, {x-20/scale, y-28/scale}, {x-15/scale, y-29/scale}, {x-5/scale, y-30/scale}, {x+5/scale, y-31/scale},
        {x+7/scale, y-31/scale}, {x+25/scale, y-29/scale}, {x+30/scale, y-28/scale}, {x+35/scale, y-26/scale}, {x+41/scale, y-23/scale}};
        POINT leftShadowVisorCap [10] = {{x-20/scale, y-65/scale}, {x-29/scale, y-55/scale}, {x-32/scale, y-45/scale}, {x-34/scale, y-35/scale}, {x-33/scale, y-25/scale},
        {x-32/scale, y-21/scale}, {x-30/scale, y-25/scale}, {x-28/scale, y-29/scale}, {x-28/scale, y-45/scale}, {x-20/scale, y-65/scale}};
        POINT leftShadowMainCap [26] = {{x-23/scale, y-35/scale}, {x-28/scale, y-29/scale}, {x-30/scale, y-25/scale}, {x-32/scale, y-21/scale}, {x-35/scale, y-16/scale},
        {x-40/scale, y-5/scale}, {x-43/scale, y+5/scale}, {x-45/scale, y+15/scale}, {x-48/scale, y+25/scale}, {x-47/scale, y+35/scale},
        {x-45/scale, y+43/scale}, {x-41/scale, y+55/scale}, {x-38/scale, y+62/scale}, {x-32/scale, y+71/scale},{x-25/scale, y+75/scale},
        {x-30/scale, y+65/scale}, {x-32/scale, y+55/scale}, {x-35/scale, y+45/scale}, {x-36/scale, y+25/scale}, {x-36/scale, y+15/scale},
        {x-34/scale, y+5/scale}, {x-32/scale, y-5/scale}, {x-30/scale, y-15/scale}, {x-27/scale, y-23/scale}, {x-25/scale, y-31/scale},
        {x-23/scale, y-35/scale}};

        POINT symbolI [13] = {{x+13/scale, y-46/scale}, {x+5/scale, y-46/scale}, {x+5/scale, y-48/scale}, {x+8/scale, y-48/scale}, {x+8/scale, y-52/scale},
        {x+5/scale, y-52/scale}, {x+5/scale, y-54/scale}, {x+13/scale, y-54/scale}, {x+13/scale, y-52/scale}, {x+10/scale, y-52/scale},
        {x+10/scale, y-48/scale}, {x+13/scale, y-48/scale}, {x+13/scale, y-46/scale}};
        POINT symbolT [9] = {{x+3/scale, y-46/scale}, {x-5/scale, y-46/scale}, {x-5/scale, y-48/scale}, {x-2/scale, y-48/scale}, {x-2/scale, y-54/scale},
        {x-0/scale, y-54/scale}, {x-0/scale, y-48/scale}, {x+3/scale, y-48/scale}, {x+3/scale, y-46/scale}};
        POINT symbolSH [13] = {{x+26/scale, y-56/scale}, {x+26/scale, y-64/scale}, {x+18/scale, y-64/scale}, {x+18/scale, y-56/scale}, {x+20/scale, y-56/scale},
        {x+20/scale, y-62/scale}, {x+21/scale, y-62/scale}, {x+21/scale, y-56/scale}, {x+23/scale, y-56/scale}, {x+23/scale, y-62/scale},
        {x+24/scale, y-62/scale}, {x+24/scale, y-56/scale}, {x+26/scale, y-56/scale}};
        POINT symbolK [14] = {{x+16/scale, y-56/scale}, {x+16/scale, y-64/scale}, {x+13/scale, y-64/scale}, {x+13/scale, y-62/scale}, {x+11/scale, y-64/scale},
        {x+8/scale, y-64/scale}, {x+9/scale, y-64/scale}, {x+13/scale, y-60/scale}, {x+8/scale, y-57/scale}, {x+8/scale, y-56/scale},
        {x+10/scale, y-56/scale}, {x+13/scale, y-58/scale}, {x+13/scale, y-56/scale}, {x+16/scale, y-56/scale}};
        POINT symbolO [9] = {{x+5/scale, y-56/scale}, {x+8/scale, y-59/scale}, {x+8/scale, y-61/scale}, {x+5/scale, y-64/scale}, {x+3/scale, y-64/scale},
        {x-0/scale, y-61/scale}, {x-0/scale, y-59/scale}, {x+3/scale, y-56/scale}, {x+5/scale, y-56/scale}};
        POINT voidSymbolO [9] = {{x+5/scale, y-58/scale}, {x+6/scale, y-57/scale}, {x+6/scale, y-61/scale}, {x+5/scale, y-62/scale}, {x+3/scale, y-62/scale},
        {x+2/scale, y-61/scale}, {x+2/scale, y-59/scale}, {x+3/scale, y-58/scale}, {x+5/scale, y-58/scale}};
        POINT symbolL [9] = {{x-4/scale, y-56/scale}, {x-1/scale, y-64/scale}, {x-3/scale, y-64/scale}, {x-4.2/scale, y-58/scale}, {x-5.8/scale, y-58/scale},
        {x-7/scale, y-64/scale}, {x-9/scale, y-64/scale}, {x-6/scale, y-56/scale}, {x-4/scale, y-56/scale}};
        POINT symbolA [9] = {{x-13/scale, y-56/scale}, {x-10/scale, y-64/scale}, {x-8/scale, y-64/scale}, {x-12.6/scale, y-61/scale}, {x-15.4/scale, y-61/scale},
        {x-16/scale, y-64/scale}, {x-18/scale, y-64/scale}, {x-15/scale, y-56/scale}, {x-13/scale, y-56/scale}};
        POINT voidSymbolA [5] = {{x-13.2/scale, y-58/scale}, {x-12.8/scale, y-60/scale}, {x-15.2/scale, y-60/scale}, {x-14.8/scale, y-58/scale}, {x-13.2/scale, y-58/scale}};

        txSetFillColor(mainColorCap);
        txSetColor(mainColorCap);
        txPolygon(bodyCap, 41);
        txPolygon(visorCap, 16);
        txSetFillColor(lightShadowColorCap);
        txSetColor(lightShadowColorCap);
        txPolygon(leftShadowMainCap, 26);
        txPolygon(upShadowMainCap, 20);
        txPolygon(downShadowMainCap, 18);
        txPolygon(leftShadowVisorCap, 10);
        txSetFillColor(darkShadowColorCap);
        txSetColor(darkShadowColorCap);
        txPolygon(rightShadowMainCap, 22);

        txSetFillColor(colorButtonCap);
        txSetColor(TX_BLACK);
        txCircle(x-0/scale, y+20/scale, 5/scale);
        txSetFillColor(colorLogoCap);
        txPolygon(symbolI, 13);
        txPolygon(symbolT, 9);
        txPolygon(symbolSH, 13);
        txPolygon(symbolK, 14);
        txPolygon(symbolO, 9);
        txPolygon(symbolL, 9);
        txPolygon(symbolA, 9);
        txSetFillColor(mainColorCap);
        txPolygon(voidSymbolO, 9);
        txPolygon(voidSymbolA, 5);
    }
    if (direction==LEFT)
    {
        POINT bodyCap [41] = {{x+75/scale, y-10/scale}, {x+73/scale, y-15/scale}, {x+70/scale, y-20/scale}, {x+66/scale, y-25/scale}, {x+61/scale, y-30/scale},
        {x+55/scale, y-35/scale}, {x+50/scale, y-38/scale}, {x+45/scale, y-40/scale}, {x+40/scale, y-44/scale}, {x+35/scale, y-45/scale},
        {x+32/scale, y-47/scale}, {x+15/scale, y-47/scale}, {x+5/scale, y-46/scale}, {x-5/scale, y-45/scale}, {x-15/scale, y-43/scale},
        {x-23/scale, y-41/scale}, {x-29/scale, y-39/scale}, {x-35/scale, y-34/scale}, {x-41/scale, y-25/scale}, {x-45/scale, y-15/scale},
        {x-45/scale, y-5/scale}, {x-43/scale, y+5/scale}, {x-39/scale, y+15/scale}, {x-35/scale, y+23/scale}, {x-31/scale, y+25/scale},
        {x-29/scale, y+28/scale}, {x-25/scale, y+30/scale}, {x-21/scale, y+32/scale}, {x-16/scale, y+35/scale}, {x-5/scale, y+40/scale},
        {x+5/scale, y+43/scale}, {x+15/scale, y+45/scale}, {x+25/scale, y+48/scale}, {x+35/scale, y+47/scale}, {x+43/scale, y+45/scale},
        {x+55/scale, y+41/scale}, {x+62/scale, y+38/scale}, {x+71/scale, y+32/scale}, {x+75/scale, y+25/scale}, {x+75/scale, y+23/scale},
        {x+75/scale, y-10/scale}};
        POINT visorCap [16] = {{x-29/scale, y-39/scale}, {x-35/scale, y-39/scale}, {x-45/scale, y-37/scale}, {x-50/scale, y-35/scale}, {x-66/scale, y-25/scale},
        {x-71/scale, y-20/scale}, {x-75/scale, y-10/scale}, {x-75/scale, y+3/scale}, {x-69/scale, y+15/scale}, {x-65/scale, y+20/scale},
        {x-55/scale, y+29/scale}, {x-45/scale, y+32/scale}, {x-35/scale, y+34/scale}, {x-25/scale, y+33/scale}, {x-21/scale, y+32/scale},
        {x-29/scale, y-39/scale}};
        POINT upShadowMainCap [22] = {{x+55/scale, y-35/scale}, {x+50/scale, y-38/scale}, {x+45/scale, y-40/scale}, {x+40/scale, y-44/scale}, {x+35/scale, y-45/scale},
        {x+32/scale, y-47/scale}, {x+15/scale, y-47/scale}, {x+5/scale, y-46/scale}, {x-5/scale, y-45/scale}, {x-15/scale, y-43/scale},
        {x-23/scale, y-41/scale}, {x-26/scale, y-35/scale}, {x-28/scale, y-30/scale}, {x-15/scale, y-34/scale}, {x-5/scale, y-35/scale},
        {x+25/scale, y-35/scale}, {x+35/scale, y-34/scale}, {x+45/scale, y-31/scale}, {x+55/scale, y-27/scale}, {x+58/scale, y-25/scale},
        {x+56/scale, y-32/scale}, {x+55/scale, y-35/scale}};
        POINT rightShadowMainCap [18] = {{x+72/scale, y+25/scale}, {x+75/scale, y+23/scale}, {x+75/scale, y-10/scale}, {x+73/scale, y-15/scale}, {x+70/scale, y-20/scale},
        {x+66/scale, y-25/scale}, {x+61/scale, y-30/scale}, {x+55/scale, y-35/scale}, {x+56/scale, y-32/scale}, {x+58/scale, y-25/scale},
        {x+62/scale, y-15/scale}, {x+64/scale, y-5/scale}, {x+63/scale, y+5/scale}, {x+60/scale, y+15/scale}, {x+57/scale, y+25/scale},
        {x+55/scale, y+32/scale}, {x+65/scale, y+30/scale}, {x+72/scale, y+25/scale}};
        POINT leftShadowMainCap [20] = {{x-23/scale, y-41/scale}, {x-29/scale, y-39/scale}, {x-35/scale, y-34/scale}, {x-41/scale, y-25/scale}, {x-43/scale, y-15/scale},
        {x-43/scale, y-5/scale}, {x-42/scale, y+5/scale}, {x-39/scale, y+15/scale}, {x-35/scale, y+23/scale}, {x-31/scale, y+25/scale},
        {x-23/scale, y+27/scale}, {x-28/scale, y+20/scale}, {x-29/scale, y+15/scale}, {x-30/scale, y+5/scale}, {x-31/scale, y-5/scale},
        {x-31/scale, y-7/scale}, {x-29/scale, y-25/scale}, {x-28/scale, y-30/scale}, {x-26/scale, y-35/scale}, {x-23/scale, y-41/scale}};
        POINT downShadowVisorCap [10] = {{x-65/scale, y+20/scale}, {x-55/scale, y+29/scale}, {x-45/scale, y+32/scale}, {x-35/scale, y+34/scale}, {x-25/scale, y+33/scale},
        {x-21/scale, y+32/scale}, {x-25/scale, y+30/scale}, {x-29/scale, y+28/scale}, {x-45/scale, y+28/scale}, {x-65/scale, y+20/scale}};
        POINT downShadowMainCap [26] = {{x-35/scale, y+23/scale}, {x-29/scale, y+28/scale}, {x-25/scale, y+30/scale}, {x-21/scale, y+32/scale}, {x-16/scale, y+35/scale},
        {x-5/scale, y+40/scale}, {x+5/scale, y+43/scale}, {x+15/scale, y+45/scale}, {x+25/scale, y+48/scale}, {x+35/scale, y+47/scale},
        {x+43/scale, y+45/scale}, {x+55/scale, y+41/scale}, {x+62/scale, y+38/scale}, {x+71/scale, y+32/scale},{x+75/scale, y+25/scale},
        {x+65/scale, y+30/scale}, {x+55/scale, y+32/scale}, {x+45/scale, y+35/scale}, {x+25/scale, y+36/scale}, {x+15/scale, y+36/scale},
        {x+5/scale, y+34/scale}, {x-5/scale, y+32/scale}, {x-15/scale, y+30/scale}, {x-23/scale, y+27/scale}, {x-31/scale, y+25/scale},
        {x-35/scale, y+23/scale}};

        POINT symbolI [13] = {{x-46/scale, y-13/scale}, {x-46/scale, y-5/scale}, {x-48/scale, y-5/scale}, {x-48/scale, y-8/scale}, {x-52/scale, y-8/scale},
        {x-52/scale, y-5/scale}, {x-54/scale, y-5/scale}, {x-54/scale, y-13/scale}, {x-52/scale, y-13/scale}, {x-52/scale, y-10/scale},
        {x-48/scale, y-10/scale}, {x-48/scale, y-13/scale}, {x-46/scale, y-13/scale}};
        POINT symbolT [9] = {{x-46/scale, y-3/scale}, {x-46/scale, y+5/scale}, {x-48/scale, y+5/scale}, {x-48/scale, y+2/scale}, {x-54/scale, y+2/scale},
        {x-54/scale, y+0/scale}, {x-48/scale, y+0/scale}, {x-48/scale, y-3/scale}, {x-46/scale, y-3/scale}};
        POINT symbolSH [13] = {{x-56/scale, y-26/scale}, {x-64/scale, y-26/scale}, {x-64/scale, y-18/scale}, {x-56/scale, y-18/scale}, {x-56/scale, y-20/scale},
        {x-62/scale, y-20/scale}, {x-62/scale, y-21/scale}, {x-56/scale, y-21/scale}, {x-56/scale, y-23/scale}, {x-62/scale, y-23/scale},
        {x-62/scale, y-24/scale}, {x-56/scale, y-24/scale}, {x-56/scale, y-26/scale}};
        POINT symbolK [14] = {{x-56/scale, y-16/scale}, {x-64/scale, y-16/scale}, {x-64/scale, y-13/scale}, {x-62/scale, y-13/scale}, {x-64/scale, y-11/scale},
        {x-64/scale, y-8/scale}, {x-64/scale, y-9/scale}, {x-60/scale, y-13/scale}, {x-57/scale, y-8/scale}, {x-56/scale, y-8/scale},
        {x-56/scale, y-10/scale}, {x-58/scale, y-13/scale}, {x-56/scale, y-13/scale}, {x-56/scale, y-16/scale}};
        POINT symbolO [9] = {{x-56/scale, y-5/scale}, {x-59/scale, y-8/scale}, {x-61/scale, y-8/scale}, {x-64/scale, y-5/scale}, {x-64/scale, y-3/scale},
        {x-61/scale, y+0/scale}, {x-59/scale, y+0/scale}, {x-56/scale, y-3/scale}, {x-56/scale, y-5/scale}};
        POINT voidSymbolO [9] = {{x-58/scale, y-5/scale}, {x-57/scale, y-6/scale}, {x-61/scale, y-6/scale}, {x-62/scale, y-5/scale}, {x-62/scale, y-3/scale},
        {x-61/scale, y-2/scale}, {x-59/scale, y-2/scale}, {x-58/scale, y-3/scale}, {x-58/scale, y-5/scale}};
        POINT symbolL [9] = {{x-56/scale, y+4/scale}, {x-64/scale, y+1/scale}, {x-64/scale, y+3/scale}, {x-58/scale, y+4.2/scale}, {x-58/scale, y+5.8/scale},
        {x-64/scale, y+7/scale}, {x-64/scale, y+9/scale}, {x-56/scale, y+6/scale}, {x-56/scale, y+4/scale}};
        POINT symbolA [9] = {{x-56/scale, y+13/scale}, {x-64/scale, y+10/scale}, {x-64/scale, y+8/scale}, {x-61/scale, y+12.6/scale}, {x-61/scale, y+15.4/scale},
        {x-64/scale, y+16/scale}, {x-64/scale, y+18/scale}, {x-56/scale, y+15/scale}, {x-56/scale, y+13/scale}};
        POINT voidSymbolA [5] = {{x-58/scale, y+13.2/scale}, {x-60/scale, y+12.8/scale}, {x-60/scale, y+15.2/scale}, {x-58/scale, y+14.8/scale}, {x-58/scale, y+13.2/scale}};

        txSetFillColor(mainColorCap);
        txSetColor(mainColorCap);
        txPolygon(bodyCap, 41);
        txPolygon(visorCap, 16);
        txSetFillColor(lightShadowColorCap);
        txSetColor(lightShadowColorCap);
        txPolygon(upShadowMainCap, 22);
        txPolygon(leftShadowMainCap, 20);
        txPolygon(downShadowMainCap, 26);
        txPolygon(downShadowVisorCap, 10);
        txSetFillColor(darkShadowColorCap);
        txSetColor(darkShadowColorCap);
        txPolygon(rightShadowMainCap, 18);

        txSetFillColor(colorButtonCap);
        txSetColor(TX_BLACK);
        txCircle(x+20/scale, y-0/scale, 5/scale);
        txSetFillColor(colorLogoCap);
        txPolygon(symbolI, 13);
        txPolygon(symbolT, 9);
        txPolygon(symbolSH, 13);
        txPolygon(symbolK, 14);
        txPolygon(symbolO, 9);
        txPolygon(symbolL, 9);
        txPolygon(symbolA, 9);
        txSetFillColor(mainColorCap);
        txPolygon(voidSymbolO, 9);
        txPolygon(voidSymbolA, 5);
    }
}

/**
    1) x - x coordinate of fog
    2) y - y coordinate of fog
**/
void drawFog(int x, int y)
{
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, x-125, MAX_Y);
    txRectangle(MIN_X, MIN_Y, MAX_X, y-125);
    txRectangle(x+125, MIN_Y, MAX_X, MAX_Y);
    txRectangle(MIN_X, y+125, MAX_X, MAX_Y);
}

/**
    1) x - x coordinate of bridge
    2) y - y coordinate of bridge
**/
void drawBridge(int x, int y)
{
    COLORREF colorBoardsFromBelow = RGB(203, 110, 0);
    COLORREF colorBoardsFromAbove = RGB(255, 190, 0);
    COLORREF colorNail = RGB(145, 137, 113);

    txSetFillColor(colorBoardsFromBelow);
    txSetColor(colorBoardsFromBelow);
    for (int i=0; i<BOARDS; ++i)
    {
        txRectangle(x+0, y+0+42*i, x+200, y+32+42*i);
    }
    txSetFillColor(colorBoardsFromAbove);
    txSetColor(colorBoardsFromAbove);
    for (int i=0; i<BOARDS; ++i)
    {
        txRectangle(x+0+42*i, y+0, x+32+42*i, y+200);
    }
    txSetFillColor(colorNail);
    txSetColor(colorNail);
    for (int i=0; i<NAILS; ++i)
    {
        for (int j=0; j<NAILS; ++j)
        {
            txCircle(x+16+42*j, y+16+42*i, 3);
        }
    }
}

/**
    1) x - x coordinate of grass
    2) y - y coordinate of grass
    3) type - type of grass
**/
void drawGrass(int x, int y, int type)
{
    COLORREF colorGrass = RGB(13, 172, 43);
    txSetFillColor(colorGrass);
    txSetColor(colorGrass);
    if (type==1)
    {
        POINT grass1[15] = {{x+10, y+50}, {x+10, y+42}, {x+16, y+32}, {x+20, y+28}, {x+30, y+20},
        {x+34, y+16}, {x+38, y+10}, {x+40, y+0}, {x+40, y+12}, {x+36, y+22},
        {x+30, y+28}, {x+20, y+36}, {x+18, y+40}, {x+16, y+50}, {x+10, y+50}};
        txPolygon(grass1, 15);
    }
    if (type==2)
    {
        POINT grass2[12] = {{x+10, y+50}, {x+10, y+40}, {x+14, y+30}, {x+20, y+20}, {x+28, y+10},
        {x+40, y+0}, {x+34, y+10}, {x+30, y+16}, {x+24, y+30}, {x+20, y+40},
        {x+20, y+50}, {x+10, y+50}};
        txPolygon(grass2, 12);
    }
}

/**
    1) x - x coordinate of fence
    2) y - y coordinate of fence
    3) direction - direction of fence (0 - fence by y coordinate; 1 - fence by x coordinate)
**/
void drawFence(int x, int y, int direction)
{
    COLORREF colorShadowFence = RGB(178, 102, 0);
    COLORREF colorLightFence = RGB(255, 173, 0);
    txSetFillColor(colorShadowFence);
    txSetColor(colorShadowFence);

    if (direction==0)
    {
        txRectangle(x+0, y+0, x+10, y+20);
        txSetFillColor(colorLightFence);
        txSetColor(colorLightFence);
        txRectangle(x+0, y+20, x+10, y+40);
    }
    if (direction==1)
    {
        txRectangle(x+20, y+0, x+40, y+10);
        txSetFillColor(colorLightFence);
        txSetColor(colorLightFence);
        txRectangle(x+0, y+0, x+20, y+10);
    }
}

/**
    1) xLeft - left x coordinate of fence board
    2) yLeft - left y coordinate of fence board
    3) xRight - right x coordinate of fence board
    4) yRight - right y coordinate of fence board
**/
void drawFenceBoard(int xLeft, int yLeft, int xRight, int yRight)
{
    COLORREF colorFenceBoard = RGB(169, 101, 6);
    txSetFillColor(colorFenceBoard);
    txSetColor(colorFenceBoard);
    txRectangle(xLeft, yLeft, xRight, yRight);
}

/**
    1) xLeft - left x coordinate of puddle
    2) yLeft - left y coordinate of puddle
    3) xRight - right x coordinate of puddle
    4) yRight - right y coordinate of puddle
**/
void drawPuddle(int xLeft, int yLeft, int xRight, int yRight)
{
    COLORREF colorPuddle = RGB(60, 128, 221);
    txSetFillColor(colorPuddle);
    txSetColor(colorPuddle);
    txRectangle(xLeft, yLeft, xRight, yRight);
}

/**
    1) x - x coordinate of wave
    2) y - y coordinate of wave
**/
void drawWave(int x, int y)
{
    COLORREF colorWave = RGB(45, 103, 204);
    txSetFillColor(colorWave);
    txSetColor(colorWave, 5);
    txLine(x+12, y+40, x+20, y+38);
    txLine(x+20, y+38, x+24, y+32);
    txLine(x+24, y+32, x+24, y+25);
    txLine(x+24, y+25, x+15, y+10);
    txLine(x+15, y+10, x+18, y+2);
    txLine(x+18, y+2, x+22, y+2);
}

/**
    1) x - x coordinate of rock
    2) y - y coordinate of rock
**/
void drawRock(int x, int y)
{
    COLORREF colorRock = RGB(103, 103, 102);
    txSetFillColor(colorRock);
    txSetColor(TX_BLACK);
    POINT rock[15] = {{x+6, y+0}, {x+5, y+1}, {x+3, y+6}, {x+1, y+10}, {x+0, y+12},
    {x+0, y+34}, {x+4, y+38}, {x+5, y+40}, {x+14, y+40}, {x+16, y+35},
    {x+20, y+28}, {x+20, y+11}, {x+18, y+5}, {x+12, y+0}, {x+6, y+0}};
    txPolygon(rock, 15);
}

/**
    1) x - x coordinate of portal
    2) y - y coordinate of portal
**/
void drawPortal(int x, int y)
{
    COLORREF colorBackPortal = RGB(123, 150, 210);
    COLORREF colorCenterPortal = RGB(81, 100, 139);
    COLORREF colorBranchPortal = RGB(137, 116, 201);
    txSetFillColor(colorBackPortal);
    txSetColor(colorBackPortal);
    txCircle(x+100, y+100, 98);
    txSetFillColor(colorCenterPortal);
    txSetColor(colorCenterPortal);
    txCircle(x+100, y+100, 20);
    txSetFillColor(colorBranchPortal);
    txSetColor(colorBranchPortal);
    POINT branchPortal1[10] = {{x+66, y+28}, {x+74, y+28}, {x+80, y+38}, {x+96, y+56}, {x+102, y+84},
    {x+104, y+60}, {x+102, y+40}, {x+90, y+20}, {x+80, y+22}, {x+66, y+28}};
    POINT branchPortal2[9] = {{x+18, y+60}, {x+16, y+102}, {x+40, y+96}, {x+56, y+90}, {x+76, y+92},
    {x+92, y+98}, {x+80, y+80}, {x+50, y+74}, {x+18, y+60}};
    POINT branchPortal3[9] = {{x+38, y+152}, {x+46, y+162}, {x+48, y+146}, {x+74, y+120}, {x+92, y+108},
    {x+70, y+110}, {x+44, y+132}, {x+40, y+140}, {x+38, y+152}};
    POINT branchPortal4[9] = {{x+85, y+184}, {x+104, y+185}, {x+96, y+176}, {x+97, y+116}, {x+88, y+120},
    {x+80, y+140}, {x+80, y+164}, {x+82, y+178}, {x+85, y+184}};
    POINT branchPortal5[8] = {{x+124, y+180}, {x+148, y+170}, {x+138, y+162}, {x+132, y+160}, {x+106, y+120},
    {x+108, y+140}, {x+118, y+160}, {x+124, y+180}};
    POINT branchPortal6[10] = {{x+180, y+130}, {x+184, y+108}, {x+176, y+117}, {x+164, y+120}, {x+140, y+120},
    {x+114, y+108}, {x+122, y+120}, {x+140, y+130}, {x+174, y+132}, {x+180, y+130}};
    POINT branchPortal7[10] = {{x+164, y+44}, {x+160, y+40}, {x+145, y+34}, {x+145, y+55}, {x+138, y+80},
    {x+120, y+96}, {x+130, y+96}, {x+144, y+84}, {x+162, y+60}, {x+164, y+44}};
    txPolygon(branchPortal1, 10);
    txPolygon(branchPortal2, 9);
    txPolygon(branchPortal3, 9);
    txPolygon(branchPortal4, 9);
    txPolygon(branchPortal5, 8);
    txPolygon(branchPortal6, 10);
    txPolygon(branchPortal7, 10);
}

/**
    1) x - x coordinate of secret
    2) y - y coordinate of secret
    3) phaseSecret - phase of change of position of secret
    4) directionSecret - direction of secret
**/
void drawSecret(int x, int y, int *phaseSecret, enum DirectionSecret *directionSecret)
{
    int movement = *phaseSecret;
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(x+50, y+100, x+150, y+150);
    txSetFillColor(TX_WHITE);
    txRectangle(x+50, y+50-5*movement, x+150, y+150-5*movement);
    txSelectFont("Arial", 45, 15);
    txDrawText(x+75, y+75-5*movement, x+125, y+125-5*movement, "?");

    if (*directionSecret==MOVE_UP and *phaseSecret<10)
    {
        *phaseSecret = movement+1;
    }
    if (*directionSecret==MOVE_UP and *phaseSecret==10)
    {
        *directionSecret = MOVE_DOWN;
    }
    if (*directionSecret==MOVE_DOWN and *phaseSecret>0)
    {
        *phaseSecret = movement-1;
    }
    if (*directionSecret==MOVE_DOWN and *phaseSecret==0)
    {
        *directionSecret = MOVE_UP;
    }
}

/**
    1) developerMonolueNumber - developer monologue number in game development
**/
void drawDeveloperMonologue(int *developerMonologueNumber)
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_WHITE);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSelectFont("Comic Sans MS", 60, 20);
    txSetFillColor(TX_BLACK);
    if (*developerMonologueNumber==0)
    {
        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "����������, �����. ��, ����� ����� ���������� \n�������� �����, �� ����� � ������� �� ����. �������, �� ���������� � ���\n(����� ������ ��� �����������).");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "�����, ���� ������ ������� ����, ������� ������� \n� ���������� ����� ��� �����-���� ����������. \n�� ��� ����� ���� �, ����������� ����� �����.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "�� ����������� � ���������������� ���������� ����: \n�� �������� ������� (���� ��� ����� �������), \n�� ������������ �������� ������ ��������.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "� �������� ���� ��� ������������� � ���, \n��� ����� � �����, ������� �� � \n�� ������ ����� ���� � ������ ��� ���������.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);
    }

    if (*developerMonologueNumber==1)
    {
        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "� ���� ���� �� �� �������? ������� ������ ���� ��������, \n��� �� ��� ������������� �� �������, ��� ����. \n�� ����, ���� ������� � ��������� ����.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "�������, ��� ����� �� ������ ��������, \n�� ���� �������� ��� ��������. ����� �� � ���������, \n����� � ������� ������ � ��������.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);
    }

    if (*developerMonologueNumber==2)
    {
        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "��� ��� ��� ���� ����� - ����� ������ � ����, \n�� �� �������� ������, ��� ����� ���� �����: ��������� \n(��� ������� �� ����� �� ������).");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "����� �������� ������� ��������, ���� ������� \n��� 4 ������� �� ����� ������ ����, \n������� ����������� ����� ���������������� ���������.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);

        for (int i=0; i<QUANTITY_RECTANGLES_IN_MONOLOGUE; ++i)
        {
            txSetColor(TX_WHITE);
            txDrawText(100, 250, 900, 800, "����� �� ������ ��������� \n��������������� �������, ��� ���� ����� ��� \n� �� ������� ���� ��-�� ����.");
            txSetColor(TX_BLACK);
            txRectangle(100, 200+5*i, 900, 800);
            txSleep(10);
            if (GetAsyncKeyState(VK_SPACE))
            {
                i = QUANTITY_RECTANGLES_IN_MONOLOGUE-2;
            }
        }

        txSleep(TIME_FOR_PRESS_SPACE);
        while (!GetAsyncKeyState(VK_SPACE))
        {}
        txSleep(TIME_FOR_PRESS_SPACE);
    }

    *developerMonologueNumber += 1;
}

/**
    1) phaseSecret - phase of change of position of secret
**/
void drawGettingSecret(int *phaseSecret)
{
    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK);
    txRectangle(300, 400, 700, 600);
    txSelectFont("Comic Sans MS", 80, 15);
    txDrawText(325, 425, 675, 575, "�� ���������� \n������");
    txSleep(2000);
    *phaseSecret = 0;
}

/**
    1) update - type of update the game
**/
void drawGettingUpdate(enum Updates update)
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);

    for (int i=1; i<QUANTITY_RECTANGLES_IN_UPDATE; ++i)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 50*i);
        txSleep(25);
    }

    txSetColor(TX_BLACK);
    txRectangle(300, 400, 700, 600);

    txSelectFont("Comic Sans MS", 80, 15);

    if (update==GRAFIC)
    {
        txDrawText(325, 425, 675, 575, "�� �������������� \n�������");
    }

    if (update==MECHANIC)
    {
        txDrawText(325, 425, 675, 575, "�� �������������� \n��������");
    }

    if (update==SECRETS)
    {
        txDrawText(325, 425, 675, 575, "�� �������������� \n�������");
    }

    if (update==STORY)
    {
        txDrawText(325, 425, 675, 575, "�� �������������� \n�����");
    }

    txSleep(2000);
}

/**
    1) xLeft - left x coordinate of part of grafic place
    2) yLeft - left y coordinate of part of grafic place
    3) xRight - right x coordinate of part of grafic place
    4) yRight - right y coordinate of part of grafic place
    5) number - number of part of grafic place
    6) type - type of part of grafic place
    7) positionGrafic - hero position to determine the visible part of the map
**/
void drawGraficPlace(int xLeft, int yLeft, int xRight, int yRight, int number, int type, int *positionGrafic)
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);

    if (type==0)
    {
        if ((number==1 and *positionGrafic==1) or
        (number==2 and (*positionGrafic==1 or *positionGrafic==2)) or
        (number==3 and (*positionGrafic==2 or *positionGrafic==3 or *positionGrafic==0)) or
        (number==4 and (*positionGrafic==3 or *positionGrafic==4 or *positionGrafic==0)) or
        (number==5 and (*positionGrafic==3 or *positionGrafic==4 or *positionGrafic==5)) or
        (number==6 and (*positionGrafic==5 or *positionGrafic==6)) or
        (number==7 and (*positionGrafic==6 or *positionGrafic==7)) or
        (number==8 and (*positionGrafic==7 or *positionGrafic==8)) or
        (number==9 and *positionGrafic==8))
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
        }
    }

    if (type==1)
    {
        if ((number==1 and (*positionGrafic==2 or *positionGrafic==3 or *positionGrafic==0)) or
        (number==2 and (*positionGrafic==1 or *positionGrafic==2 or *positionGrafic==3 or *positionGrafic==0)) or
        (number==3 and (*positionGrafic==2 or *positionGrafic==3 or *positionGrafic==4 or *positionGrafic==0)) or
        (number==4 and (*positionGrafic==3 or *positionGrafic==4 or *positionGrafic==5 or *positionGrafic==6)) or
        (number==5 and (*positionGrafic==5 or *positionGrafic==6 or *positionGrafic==7)) or
        (number==6 and (*positionGrafic==6 or *positionGrafic==7 or *positionGrafic==8)) or
        (number==7 and (*positionGrafic==7 or *positionGrafic==8)))
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
        }
    }

    txRectangle(xLeft, yLeft, xRight, yRight);
}

void drawBackgroundWithGrafic()
{
    COLORREF colorBackground = RGB(65, 186, 68);
    txSetFillColor(colorBackground);
    txSetColor(colorBackground);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    drawGrass(50, 50, 1);
    drawGrass(350, 150, 1);
    drawGrass(250, 530, 1);
    drawGrass(210, 300, 1);
    drawGrass(550, 850, 1);
    drawGrass(150, 250, 1);
    drawGrass(670, 150, 1);
    drawGrass(600, 550, 1);
    drawGrass(850, 630, 1);
    drawGrass(450, 750, 1);
    drawGrass(100, 500, 1);
    drawGrass(130, 760, 1);
    drawGrass(170, 810, 1);

    drawGrass(120, 230, 2);
    drawGrass(290, 840, 2);
    drawGrass(310, 510, 2);
    drawGrass(110, 850, 2);
    drawGrass(560, 460, 2);
    drawGrass(610, 110, 2);
    drawGrass(750, 830, 2);
    drawGrass(820, 490, 2);
    drawGrass(570, 310, 2);
    drawGrass(420, 870, 2);
    drawGrass(800, 120, 2);
    drawGrass(890, 350, 2);
    drawGrass(910, 410, 2);
}

/**
    1) x - x coordinate of fence
**/
void drawBackgroundInFakeGame(int x)
{
    drawBackgroundInTheGame();
    COLORREF colorBackground = RGB(65, 186, 68);
    txSetFillColor(colorBackground);
    txSetColor(colorBackground);
    txRectangle(725, 900, MAX_X, MAX_Y);

    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, 399, MAX_X, 401);
    txRectangle(MIN_X, 599, MAX_X, 601);

    drawFenceBoard(MIN_X, 195, MAX_X, 200);
    drawFenceBoard(MIN_X, 800, MAX_X, 805);

    for (int i=0; i<BACKGROUND; ++i)
    {
        drawFence(MIN_X+x+50*i, 190, 1);
        drawFence(10+x+50*i, 800, 1);
    }
}

void drawBackgroundInTheGame()
{
    COLORREF colorBackground = RGB(65, 186, 68);
    txSetFillColor(colorBackground);
    txSetColor(colorBackground);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    drawGrass(100, 100, 1);
    drawGrass(140, 40, 1);
    drawGrass(20, 600, 1);
    drawGrass(400, 240, 1);
    drawGrass(800, 700, 1);
    drawGrass(239, 821, 1);
    drawGrass(380, 690, 1);
    drawGrass(360, 280, 1);
    drawGrass(750, 920, 1);
    drawGrass(540, 600, 1);
    drawGrass(460, 700, 1);
    drawGrass(230, 300, 1);
    drawGrass(790, 30, 1);
    drawGrass(930, 120, 1);
    drawGrass(520, 70, 1);

    drawGrass(210, 400, 2);
    drawGrass(850, 500, 2);
    drawGrass(30, 300, 2);
    drawGrass(400, 900, 2);
    drawGrass(800, 540, 2);
    drawGrass(230, 100, 2);
    drawGrass(90, 450, 2);
    drawGrass(600, 300, 2);
    drawGrass(790, 400, 2);
    drawGrass(300, 900, 2);
    drawGrass(180, 560, 2);
    drawGrass(850, 340, 2);
    drawGrass(900, 100, 2);
    drawGrass(860, 90, 2);
    drawGrass(650, 50, 2);

    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txSelectFont("Comic Sans MS", 30, 10);
    txTextOut(725, 940, "�����-������������ 1.0");
}

void drawBeginningInTheGame()
{
    drawBackgroundInTheGame();
    drawFenceBoard(195, 195, 805, 200);
    drawFenceBoard(195, 195, 200, 805);
    drawFenceBoard(195, 800, 805, 805);
    drawFenceBoard(800, 600, 805, 805);
    drawFenceBoard(800, 600, MAX_X, 605);
    drawFenceBoard(800, 195, 805, 400);
    drawFenceBoard(800, 395, MAX_X, 400);

    for (int i=0; i<TWELVE_FENCES_IN_GAME; ++i)
    {
        drawFence(200+50*i, 190, 1);
        drawFence(190, 200+50*i, 0);
        drawFence(200+50*i, 800, 1);
    }

    for (int i=0; i<FOUR_FENCES_IN_GAME; ++i)
    {
        drawFence(800, 210+50*i, 0);
        drawFence(800+50*i, 390, 1);
        drawFence(800, 600+50*i, 0);
        drawFence(810+50*i, 600, 1);
    }
}

/**
    1) destroyRock - checking for destruction of stone
**/
void drawForkInTheGame(bool destroyRock)
{
    drawBackgroundInTheGame();
    drawFenceBoard(MIN_X, 395, 200, 400);
    drawFenceBoard(195, 195, 200, 400);
    drawFenceBoard(195, 195, 400, 200);
    drawFenceBoard(395, MIN_Y, 400, 200);

    drawFenceBoard(600, MIN_Y, 605, 200);
    drawFenceBoard(600, 195, 805, 200);
    drawFenceBoard(800, 195, 805, 400);
    drawFenceBoard(800, 395, MAX_X, 400);

    drawFenceBoard(MIN_X, 600, 200, 605);
    drawFenceBoard(195, 600, 200, 805);
    drawFenceBoard(195, 800, 400, 805);
    drawFenceBoard(395, 800, 400, MAX_Y);

    drawFenceBoard(600, 800, 605, MAX_Y);
    drawFenceBoard(600, 800, 805, 805);
    drawFenceBoard(800, 600, 805, 805);
    drawFenceBoard(800, 600, MAX_X, 605);

    for (int i=0; i<FOUR_FENCES_IN_GAME; ++i)
    {
        drawFence(MIN_X+50*i, 390, 1);
        drawFence(190, 200+50*i, 0);
        drawFence(200+50*i, 190, 1);
        drawFence(390, MIN_Y+50*i, 0);

        drawFence(600, 10+50*i, 0);
        drawFence(610+50*i, 190, 1);
        drawFence(800, 210+50*i, 0);
        drawFence(800+50*i, 390, 1);

        drawFence(10+50*i, 600, 1);
        drawFence(190, 600+50*i, 0);
        drawFence(210+50*i, 800, 1);
        drawFence(390, 800+50*i, 0);

        drawFence(600, 800+50*i, 0);
        drawFence(600+50*i, 800, 1);
        drawFence(800, 600+50*i, 0);
        drawFence(800+50*i, 600, 1);
    }

    if (!destroyRock)
    {
        for (int i=0; i<ROCKS_ON_Y; ++i)
        {
            for (int j=0; j<ROCKS_ON_X; ++j)
            {
                drawRock(400+20*j, MIN_Y+40*i);
            }
        }
    }
}

void drawSecretPlaceInTheGame()
{
    drawBackgroundInTheGame();
    drawFenceBoard(MIN_X, 495, MAX_X, 500);
    drawFenceBoard(100, 595, 900, 600);
    drawFenceBoard(95, 595, 100, 805);
    drawFenceBoard(900, 595, 905, 805);
    drawFenceBoard(100, 800, 400, 805);
    drawFenceBoard(600, 800, 900, 805);
    drawFenceBoard(395, 800, 400, MAX_X);
    drawFenceBoard(600, 800, 605, MAX_X);

    for (int i=0; i<SIXTEEN_FENCES_IN_GAME; ++i)
    {
        drawFence(100+50*i, 590, 1);
    }

    for (int i=0; i<FOUR_FENCES_IN_GAME; ++i)
    {
        drawFence(90, 590+50*i, 0);
        drawFence(900, 600+50*i, 0);
        drawFence(390, 800+50*i, 0);
        drawFence(600, 810+50*i, 0);
    }

    for (int i=0; i<SIX_FENCES_IN_GAME; ++i)
    {
        drawFence(110+50*i, 800, 1);
        drawFence(600+50*i, 800, 1);
    }

    drawPuddle(0, 300, 1000, 500);

    drawWave(100, 310);
    drawWave(250, 430);
    drawWave(320, 420);
    drawWave(410, 410);
    drawWave(470, 360);
    drawWave(560, 370);
    drawWave(610, 360);
    drawWave(780, 410);
    drawWave(840, 320);
    drawWave(970, 390);
}

/**
    1) secrets - number of secrets to improve the town
    2) update - first update in game development to choosing a house
**/
void drawTownInTheGame(int secrets, enum Updates update)
{
    COLORREF colorRoad = RGB(138, 148, 156);

    drawBackgroundInTheGame();
    drawFenceBoard(95, MIN_Y, 100, 905);
    drawFenceBoard(95, 900, MAX_X, 905);
    drawFenceBoard(300, MIN_Y, 305, 100);
    drawFenceBoard(300, 95, 905, 100);
    drawFenceBoard(900, 95, 905, 700);
    drawFenceBoard(900, 695, MAX_X, 700);

    for (int i=0; i<EIGHTEEN_FENCES_IN_GAME; ++i)
    {
        drawFence(90, MIN_Y+50*i, 0);
        drawFence(110+50*i, 900, 1);
    }

    for (int i=0; i<TWO_FENCES_IN_GAME; ++i)
    {
        drawFence(300, MIN_Y+50*i, 0);
        drawFence(900+50*i, 690, 1);
    }

    for (int i=0; i<TWELVE_FENCES_IN_GAME; ++i)
    {
        drawFence(310+50*i, 90, 1);
        drawFence(900, 110+50*i, 0);
    }

    if (secrets>=1)
    {
        COLORREF colorCarpenter = RGB(210, 110, 0);
        txSetFillColor(colorCarpenter);
        txSetColor(colorCarpenter);
        txRectangle(300, 100, 600, 300);

        txSetColor(TX_BLACK);
        txSelectFont("Comic Sans MS", 90, 25);
        txDrawText(300, 100, 600, 300, "�������");

        txSetFillColor(colorRoad);
        txSetColor(colorRoad);
        txRectangle(400, 300, 500, 400);
    }

    if (secrets>=2)
    {
        COLORREF colorError = RGB(193, 0, 255);
        txSetFillColor(colorError);
        txSetColor(colorError);
        txRectangle(600, 100, 900, 300);
        txSetColor(TX_BLACK);
        txSelectFont("Times New Roman", 90, 25, 1000);
        txDrawText(600, 100, 900, 300, "ERROR");
        txSetFillColor(colorRoad);
        txSetColor(colorRoad);
        txRectangle(700, 300, 800, 400);
    }

    if (secrets>=3)
    {
        if (update==GRAFIC)//���������� - Architect
        {
            COLORREF colorArchitect = RGB(142, 152, 158);
            txSetFillColor(colorArchitect);
            txSetColor(colorArchitect);
            txRectangle(100, 700, 400, 900);
            txSetColor(TX_BLACK);
            txSelectFont("Buxton Sketch", 90, 25);
            txDrawText(100, 700, 400, 900, "����������");
        }

        if (update==MECHANIC)//������� - Engineer
        {
            COLORREF colorEngineer = RGB(255, 174, 0);
            txSetFillColor(colorEngineer);
            txSetColor(colorEngineer);
            txRectangle(100, 700, 400, 900);
            txSetColor(TX_BLACK);
            txSelectFont("Times New Roman", 90, 25);
            txDrawText(100, 700, 400, 900, "�������");
        }

        if (update==STORY)//������������ - Librarian
        {
            COLORREF colorLibrarian = RGB(243, 253, 0);
            txSetFillColor(colorLibrarian);
            txSetColor(colorLibrarian);
            txRectangle(100, 700, 400, 900);
            txSetColor(TX_BLACK);
            txSelectFont("Times New Roman", 90, 20);
            txDrawText(100, 700, 400, 900, "������������");
        }

        if (update==SECRETS)//������� (�������, �������, �������) - Questionnaire
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);
            txRectangle(100, 700, 400, 900);
            txSetColor(TX_BLACK);
            txRectangle(200, 750, 300, 850);
            txSelectFont("Arial", 90, 25);
            txDrawText(175, 750, 325, 850, "?");
        }

        txSetFillColor(colorRoad);
        txSetColor(colorRoad);
        txRectangle(200, 600, 300, 700);
    }

    if (secrets>=4)
    {
        COLORREF colorMiner = RGB(34, 15, 15);
        txSetFillColor(colorMiner);
        txSetColor(colorMiner);
        txSetColor(TX_BLACK);
        txRectangle(400, 700, 700, 900);
        txSelectFont("Times New Roman", 90, 25);
        txDrawText(400, 700, 700, 900, "�����");
        txSetFillColor(colorRoad);
        txSetColor(colorRoad);
        txRectangle(500, 600, 600, 700);
    }
}

void drawFirstRiverInTheGame()
{
    drawBackgroundInTheGame();
    drawFenceBoard(MIN_X, 395, MAX_X, 400);
    drawFenceBoard(MIN_X, 600, MAX_X, 605);

    for (int i=0; i<TWENTY_FENCES_IN_GAME; ++i)
    {
        drawFence(MIN_X+50*i, 390, 1);
        drawFence(10+50*i, 600, 1);
    }

    drawPuddle(200, 400, 800, 600);
    drawWave(350, 420);
    drawWave(650, 500);
    drawWave(400, 550);
    drawWave(700, 410);
    drawWave(550, 450);
    drawWave(250, 520);
}

/**
    1) secrets - number of secrets
**/
void drawSecondRiverInTheGame(int secrets)
{
    drawBackgroundInTheGame();
    drawFenceBoard(MIN_X, 395, 400, 400);
    drawFenceBoard(395, 95, 400, 400);
    drawFenceBoard(395, 95, 605, 100);
    drawFenceBoard(600, 95, 605, 400);
    drawFenceBoard(600, 395, MAX_X, 400);
    drawFenceBoard(MIN_X, 600, MAX_X, 605);

    for (int i=0; i<TWENTY_FENCES_IN_GAME; ++i)
    {
        drawFence(10+50*i, 600, 1);
    }

    for (int i=0; i<EIGHT_FENCES_IN_GAME; ++i)
    {
        drawFence(MIN_X+50*i, 390, 1);
        drawFence(600+50*i, 390, 1);
    }

    for (int i=0; i<SIX_FENCES_IN_GAME; ++i)
    {
        drawFence(390, 345-50*i, 0);
        drawFence(600, 105+50*i, 0);
    }

    for (int i=0; i<FOUR_FENCES_IN_GAME; ++i)
    {
        drawFence(405+50*i, 90, 1);
    }

    drawPuddle(200, 400, MAX_X, 600);

    drawWave(220, 410);
    drawWave(260, 470);
    drawWave(350, 560);
    drawWave(390, 440);
    drawWave(470, 540);
    drawWave(540, 490);
    drawWave(690, 450);
    drawWave(780, 510);
    drawWave(840, 530);
    drawWave(980, 450);

    if (secrets==4)
    {
        COLORREF colorChest = RGB(101, 48, 5);
        txSetFillColor(colorChest);
        txSetColor(colorChest);
        txRectangle(450, 100, 550, 150);

        COLORREF darkColorChest = RGB(66, 31, 2);
        txSetFillColor(darkColorChest);
        txSetColor(darkColorChest);
        txRectangle(450, 122, 550, 128);

        COLORREF lockForChest = RGB(111, 111, 111);
        txSetFillColor(lockForChest);
        txSetColor(lockForChest);
        txRectangle(497, 128, 503, 137);
    }
}

void drawPlaceOfGreed()
{
    drawBackgroundInTheGame();
    drawFenceBoard(MIN_X, 600, 200, 605);
    drawFenceBoard(200, 200, 205, 600);
    drawFenceBoard(200, 200, 805, 205);
    drawFenceBoard(795, 195, 800, MAX_Y);
    drawFenceBoard(MIN_X, 695, 300, 700);
    drawFenceBoard(295, 300, 300, 700);
    drawFenceBoard(300, 295, 700, 300);
    drawFenceBoard(700, 295, 705, 900);
    drawFenceBoard(MIN_X, 900, 705, 905);

    drawPuddle(MIN_X, MIN_Y, 200, 600);
    drawPuddle(MIN_X, MIN_Y, MAX_X, 200);
    drawPuddle(800, MIN_Y, MAX_X, MAX_Y);

    drawWave(200, 100);
    drawWave(100, 50);
    drawWave(150, 500);
    drawWave(75, 300);
    drawWave(300, 75);
    drawWave(600, 100);
    drawWave(825, 25);
    drawWave(900, 100);
    drawWave(850, 150);
    drawWave(950, 250);
    drawWave(840, 370);
    drawWave(940, 440);
    drawWave(900, 600);
    drawWave(860, 780);
    drawWave(920, 890);

    for (int i=0; i<FOUR_FENCES_IN_GAME; ++i)
    {
        drawFence(MIN_X+50*i, 600, 1);
    }

    for (int i=0; i<SIX_FENCES_IN_GAME; ++i)
    {
        drawFence(10+50*i, 690, 1);
    }

    for (int i=0; i<EIGHT_FENCES_IN_GAME; ++i)
    {
        drawFence(200, 200+50*i, 0);
        drawFence(290, 310+50*i, 0);
        drawFence(300+50*i, 290, 1);
    }

    for (int i=0; i<TWELVE_FENCES_IN_GAME; ++i)
    {
        drawFence(200+50*i, 200, 1);
        drawFence(700, 300+50*i, 0);
    }

    for (int i=0; i<FOURTEEN_FENCES_IN_GAME; ++i)
    {
        drawFence(MIN_X+50*i, 900, 1);
    }

    for (int i=0; i<SIXTEEN_FENCES_IN_GAME; ++i)
    {
        drawFence(790, 200+50*i, 0);
    }

    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK);
    txRectangle(460, 302, 540, 402);
    txSetFillColor(TX_BLACK);
    txRectangle(470, 312, 530, 322);
    txRectangle(470, 342, 520, 352);
    txRectangle(470, 362, 520, 372);
    txRectangle(470, 382, 520, 392);
}

void drawTheEndPlace()
{
    drawBackgroundInTheGame();

    txSetColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    txRectangle(250, 400, 750, 600);

    txSelectFont("Arial", 150, 50);
    txDrawText(250, 400, 750, 600, "�����");
}

void drawStartPlaceWithoutGrafics()
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, 350, 350);
    txRectangle(650, MIN_Y, MAX_X, 350);
    txRectangle(MIN_X, 650, 350, MAX_Y);
    txRectangle(650, 650, MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txSelectFont("Arial", 30, 10);
    txRectangle(670, 20, 810, 70);
    txDrawText(685, 30, 795, 60, "�������");
    txRectangle(830, 670, 980, 720);
    txDrawText(845, 680, 965, 710, "��������");
    txRectangle(20, 270, 140, 320);
    txDrawText(35, 280, 125, 310, "�������");
    txRectangle(200, 930, 330, 980);
    txDrawText(215, 940, 315, 970, "�����");
}

void drawStartPlaceWithGrafics()
{
    COLORREF colorNameplate = RGB(225, 105, 0);
    drawBackgroundWithGrafic();
    drawFenceBoard(345, MIN_Y, 350, 350);//1
    drawFenceBoard(MIN_X, 345, 350, 350);//1
    drawFenceBoard(650, MIN_Y, 655, 350);//2
    drawFenceBoard(650, 345, MAX_X, 350);//2
    drawFenceBoard(345, 650, 350, MAX_Y);//3
    drawFenceBoard(MIN_X, 650, 350, 655);//3
    drawFenceBoard(650, 650, 655, MAX_Y);//4
    drawFenceBoard(650, 650, MAX_X, 655);//4

    for (int i=0; i<QUANTITY_FENCE_IN_START_PLACE; ++i)
    {
        drawFence(10+50*i, 340, 1);//1
        drawFence(340, 10+50*i, 0);//1
        drawFence(650+50*i, 340, 1);//2
        drawFence(650, 10+50*i, 0);//2
        drawFence(10+50*i, 650, 1);//3
        drawFence(340, 650+50*i, 0);//3
        drawFence(650, 650+50*i, 0);//4
        drawFence(650+50*i, 650, 1);//4
    }

    txSetFillColor(colorNameplate);
    txSetColor(TX_BLACK);
    txSelectFont("Arial", 30, 10);
    txRectangle(670, 20, 810, 70);
    txDrawText(685, 30, 795, 60, "�������");
    txRectangle(830, 670, 980, 720);
    txDrawText(845, 680, 965, 710, "��������");
    txRectangle(20, 270, 140, 320);
    txDrawText(35, 280, 125, 310, "�������");
    txRectangle(200, 930, 330, 980);
    txDrawText(215, 940, 315, 970, "�����");
}

/**
    1) level - level in the secret place
**/
void drawSecretPlaceWithoutGrafics(int level)
{
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    if (level==1 or level==2 or level==3)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 100);
        txRectangle(700, MIN_Y, MAX_X, 400);
        txRectangle(MIN_X, 300, 500, 700);
        txRectangle(700, 600, MAX_X, MAX_Y);
        txRectangle(MIN_X, 900, MAX_X, MAX_Y);
        txSetFillColor(TX_WHITE);
        txRectangle(200, 400, 400, 600);
        txSelectFont("Arial", 150, 50);
        txDrawText(225, 425, 375, 575, "?");
    }

    if (level==4)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 400);
        txRectangle(MIN_X, MIN_Y, 200, MAX_Y);
        txRectangle(MIN_X, 600, MAX_X, MAX_Y);
    }

    if (level==5)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 200);
        txRectangle(MIN_X, MIN_Y, 200, MAX_Y);
        txRectangle(MIN_X, 800, MAX_X, MAX_Y);
        txRectangle(500, 400, MAX_X, 600);
    }

    if (level==6)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 200);
        txRectangle(800, MIN_Y, MAX_X, 400);
        txRectangle(MIN_X, MIN_Y, 200, MAX_Y);
        txRectangle(MIN_X, 800, MAX_X, MAX_Y);
        txRectangle(800, 600, MAX_X, MAX_Y);
    }
}

/**
    1) level - level in the secret place
    2) mechanicUpdate - check for availability mechanic update
**/
void drawSecretPlaceWithGrafics(int level, bool mechanicUpdate)
{
    drawBackgroundWithGrafic();
    if (level==1 or level==2 or level==3)
    {
        txSetColor(TX_BLACK);
        txSetFillColor(TX_WHITE);
        txRectangle(200, 400, 400, 600);
        txSelectFont("Arial", 150, 50);
        txDrawText(225, 425, 375, 575, "?");
        drawFenceBoard(MIN_X, 95, 700, 100);
        drawFenceBoard(700, 95, 705, 400);
        drawFenceBoard(700, 395, MAX_X, 400);
        drawFenceBoard(MIN_X, 300, 500, 305);
        drawFenceBoard(495, 300, 500, 700);
        drawFenceBoard(MIN_X, 695, 500, 700);
        drawFenceBoard(MIN_X, 900, 700, 905);
        drawFenceBoard(700, 600, 705, 905);
        drawFenceBoard(700, 600, MAX_X, 605);
        for (int i=0; i<FENCES_IN_FIRST_LOCATION_1; ++i)
        {
            drawFence(0+50*i, 90, 1);
            drawFence(0+50*i, 900, 1);
        }
        for (int i=0; i<FENCES_IN_FIRST_LOCATION_2; ++i)
        {
            drawFence(10+50*i, 300, 1);
            drawFence(0+50*i, 690, 1);
        }
        for (int i=0; i<FENCES_IN_FIRST_LOCATION_3; ++i)
        {
            drawFence(490, 300+50*i, 0);
        }
        for (int i=0; i<FENCES_IN_FIRST_LOCATION_4; ++i)
        {
            drawFence(700, 110+50*i, 0);
            drawFence(700, 600+50*i, 0);
            drawFence(700+50*i, 390, 1);
            drawFence(700+50*i, 600, 1);
        }
        if (mechanicUpdate)
        {
            drawPuddle(500, 400, 700, 600);
            drawWave(550, 450);
            drawWave(520, 500);
            drawWave(600, 550);
            drawWave(640, 430);
            drawWave(650, 510);
        }
    }
    if (level==4)
    {
        drawFenceBoard(200, 395, MAX_X, 400);
        drawFenceBoard(195, 395, 200, 605);
        drawFenceBoard(200, 600, MAX_X, 605);
        for (int i=0; i<FENCES_IN_SECOND_LOCATION_1; ++i)
        {
            drawFence(200+50*i, 390, 1);
            drawFence(210+50*i, 600, 1);
        }
        for (int i=0; i<FENCES_IN_SECOND_LOCATION_2; ++i)
        {
            drawFence(190, 400+50*i, 0);
        }
        if (mechanicUpdate)
        {
            drawPuddle(600, 400, 800, 600);
            drawWave(650, 550);
            drawWave(620, 420);
            drawWave(670, 470);
            drawWave(720, 420);
            drawWave(740, 540);
        }
    }
    if (level==5)
    {
        drawFenceBoard(200, 195, MAX_X, 200);
        drawFenceBoard(195, 195, 200, 805);
        drawFenceBoard(200, 800, MAX_X, 805);
        drawFenceBoard(500, 400, MAX_X, 405);
        drawFenceBoard(500, 400, 505, 600);
        drawFenceBoard(500, 595, MAX_X, 600);
        for (int i=0; i<FENCES_IN_THIRD_LOCATION_1; ++i)
        {
            drawFence(200+50*i, 190, 1);
            drawFence(210+50*i, 800, 1);
        }
        for (int i=0; i<FENCES_IN_THIRD_LOCATION_2; ++i)
        {
            drawFence(190, 200+50*i, 0);
        }
        for (int i=0; i<FENCES_IN_THIRD_LOCATION_3; ++i)
        {
            drawFence(500+50*i, 400, 1);
            drawFence(510+50*i, 590, 1);
        }
        for (int i=0; i<FENCES_IN_THIRD_LOCATION_4; ++i)
        {
            drawFence(500, 400+50*i, 0);
        }
        if (mechanicUpdate)
        {
            drawPuddle(250, 400, 450, 600);
            drawWave(300, 450);
            drawWave(270, 480);
            drawWave(340, 510);
            drawWave(400, 420);
            drawWave(380, 550);
        }
    }
    if (level==6)
    {
        drawFenceBoard(800, 395, MAX_X, 400);
        drawFenceBoard(800, 200, 805, 400);
        drawFenceBoard(195, 195, 805, 200);
        drawFenceBoard(195, 200, 200, 800);
        drawFenceBoard(195, 800, 800, 805);
        drawFenceBoard(800, 600, 805, 805);
        drawFenceBoard(800, 600, MAX_X, 605);
        for (int i=0; i<FENCES_IN_FOURTH_LOCATION_1; ++i)
        {
            drawFence(200+50*i, 190, 1);
            drawFence(210+50*i, 800, 1);
            drawFence(190, 200+50*i, 0);
        }
        for (int i=0; i<FENCES_IN_FOURTH_LOCATION_2; ++i)
        {
            drawFence(800, 600+50*i, 0);
            drawFence(800, 210+50*i, 0);
            drawFence(800+50*i, 390, 1);
            drawFence(800+50*i, 600, 1);
        }
    }
}

void drawStoryPlaceWithoutGrafics()
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txRectangle(MIN_X, MIN_Y, 200, 400);
    txRectangle(400, MIN_Y, 600, 400);
    txRectangle(800, MIN_Y, MAX_X, 500);
    txRectangle(MIN_X, 550, MAX_X, 750);
    txRectangle(MIN_X, 800, 450, MAX_Y);
    txRectangle(550, 800, MAX_X, MAX_Y);
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txCircle(100, 100, 95);
    txCircle(500, 300, 95);
    txCircle(900, 100, 95);
    txCircle(900, 400, 95);
    txCircle(100, 650, 95);
    txCircle(500, 650, 95);
    txCircle(900, 650, 95);
    txCircle(350, 900, 95);
    txCircle(650, 900, 95);
}

/**
    1) mechanicUpdate - check for availability mechanic update
**/
void drawStoryPlaceWithGrafics(bool mechanicUpdate)
{
    drawBackgroundWithGrafic();
    drawPortal(MIN_X, MIN_Y);
    drawPortal(800, MIN_Y);
    drawPortal(400, 200);
    drawPortal(800, 300);
    drawPortal(MIN_Y, 550);
    drawPortal(400, 550);
    drawPortal(800, 550);
    drawPortal(250, 800);
    drawPortal(550, 800);

    for (int i=0; i<FENCE_BOARDS; ++i)
    {
        drawFenceBoard(200+400*i, MIN_Y, 205+400*i, 405);
        drawFenceBoard(-5+400*i, 400, 200+400*i, 405);
        drawFenceBoard(0+550*i, 795, 450+550*i, 800);
    }
    drawFenceBoard(395, MIN_Y, 400, 400);
    drawFenceBoard(795, MIN_Y, 800, 500);
    drawFenceBoard(795, 500, 1000, 505);
    drawFenceBoard(MIN_X, 545, MAX_X, 550);
    drawFenceBoard(MIN_X, 750, MAX_X, 755);
    drawFenceBoard(450, 795, 455, MAX_Y);
    drawFenceBoard(545, 795, 550, MAX_Y);

    for (int i=0; i<FIRST_FENCES; ++i)
    {
        drawFence(200, MIN_Y+50*i, 0);
        drawFence(390, MIN_Y+50*i, 0);
        drawFence(600, MIN_Y+50*i, 0);
    }
    for (int i=0; i<SECOND_FENCES; ++i)
    {
        drawFence(MIN_X+50*i, 790, 1);
        drawFence(550+50*i, 790, 1);
    }
    for (int i=0; i<THIRD_FENCES; ++i)
    {
        drawFence(MIN_X+50*i, 400, 1);
        drawFence(400+50*i, 400, 1);
        drawFence(810+50*i, 500, 1);
        drawFence(450, 800+50*i, 0);
        drawFence(540, 800+50*i, 0);
    }
    for (int i=0; i<FOURTH_FENCES; ++i)
    {
        drawFence(MIN_X+50*i, 540, 1);
        drawFence(10+50*i, 750, 1);
    }
    for (int i=0; i<FIFTH_FENCES; ++i)
    {
        drawFence(790, MIN_Y+50*i, 0);
    }

    if (mechanicUpdate)
    {
        drawPuddle(200, 550, 400, 750);
        drawPuddle(600, 550, 800, 750);
        drawWave(350, 560);
        drawWave(220, 670);
        drawWave(210, 580);
        drawWave(270, 630);
        drawWave(320, 700);
        drawWave(640, 600);
        drawWave(670, 650);
        drawWave(700, 700);
        drawWave(720, 620);
        drawWave(690, 570);
    }
}

/**
    1) updatesSequence - updates sequence for loading
    2) time 1 - time for first element of loading
    3) time 2 - time for second element of loading
    4) time 3 - time for third element of loading
    5) time 4 - time for fourth element of loading
    6) time 5 - time for fifth element of loading
    7) rectangleX1 - length of loading for first element of loading
    8) rectangleX2 - length of loading  for second element of loading
    9) rectangleX3 - length of loading  for third element of loading
    10) rectangleX4 - length of loading  for fourth element of loading
    11) rectangleX5 - length of loading  for fifth element of loading
**/
void drawLoading(enum Updates updatesSequence, int time1, int time2, int time3, int time4, int time5, int rectangleX1, int rectangleX2, int rectangleX3, int rectangleX4, int rectangleX5)
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txSetColor(TX_WHITE);
    txSelectFont("Arial", 60, 20);
    if (updatesSequence==LOADINGS)
    {
        txDrawText(300, 400, 700, 500, "�������� ��������");
    }
    if (updatesSequence==GRAFIC)
    {
        txDrawText(300, 400, 700, 500, "�������� �������");
    }
    if (updatesSequence==MECHANIC)
    {
        txDrawText(300, 400, 700, 500, "�������� ��������");
    }
    if (updatesSequence==SECRETS)
    {
        txDrawText(300, 400, 700, 500, "�������� ��������");
    }
    if (updatesSequence==STORY)
    {
        txDrawText(300, 400, 700, 500, "�������� ������");
    }
    txRectangle(400, 500, rectangleX1, 550);
    txSleep(time1);
    txRectangle(400, 500, rectangleX2, 550);
    txSleep(time2);
    txRectangle(400, 500, rectangleX3, 550);
    txSleep(time3);
    txRectangle(400, 500, rectangleX4, 550);
    txSleep(time4);
    txRectangle(400, 500, rectangleX5, 550);
    txSleep(time5);
    txRectangle(400, 500, 600, 550);
    txSleep(200);
}

void exit()
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(10);
    txClear();
    for (int i=1; i<FLARES_WITH_RECTANGLES_FIRST+1; ++i)
    {
        txSetFillColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSetFillColor(TX_WHITE);
        txRectangle(MIN_X, MIN_Y+100*i, MAX_X, MAX_Y-100*i);
        if (i==FLARES_WITH_RECTANGLES_FIRST)
        {
            txSleep(50);
        }
        else
        {
            txSleep(10);
        }
        txClear();
    }
    for (int i=0; i<FLARES_WITH_RECTANGLES_SECOND; i++)
    {
        txSetFillColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSetFillColor(TX_WHITE);
        txRectangle(MIN_X, 450+10*i, MAX_X, 550-10*i);
        txCircle(500, 500, 200-38*i);
        txSleep(5);
        txClear();
    }
    for (int i=0; i<FLARES_WITH_RECTANGLES_THIRD; ++i)
    {
        txSetFillColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSetFillColor(TX_WHITE);
        txRectangle(420, 492+2*i, 580, 508-2*i);
        txCircle(500, 500, 40-8*i);
        txSleep(1);
        txClear();
    }
    txSetFillColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSetFillColor(TX_WHITE);
    txCircle(500, 500, 10);
    txSleep(500);
    txClear();
    for (int i=0; i<FLARES_WITHOUT_RECTANGLES; ++i)
    {
        txSetFillColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSetFillColor(TX_WHITE);
        txCircle(500, 500, 8-2*i);
        if (i==FLARES_WITHOUT_RECTANGLES-1)
        {
            txSleep(50);
        }
        else
        {
            txSleep(100);
        }
        txClear();
    }
    txSetFillColor(TX_BLACK);
    txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
    txSleep(200);
    GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, 0);
}

void play()
{
    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);
    for (int i=0; i<QUANTITY_RECTANGLES_IN_PLAY; ++i)
    {
        txRectangle(MIN_X, MIN_Y, MAX_X, 100+50*i);
        txSleep(25);
    }
}

void training()
{
    bool training = true;
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
    bool shift = false;
    bool mouse = false;
    bool square = false;
    bool moveCheck = false;

    int moveCalc = 0;
    int xButton = 0;
    int yButton = 0;
    int acceleration = 1;

    txSetFillColor(TX_BLACK);
    txSetColor(TX_BLACK);

    for (int i=0; i<QUANTITY_RECTANGLES_IN_TRAINING; ++i)
    {
        txRectangle(650-50*i, MIN_Y, MAX_X, 320);
        txRectangle(MIN_X, 700, 350+50*i, MAX_Y);
        txSleep(50);
    }

    while(training)
    {
        txSetFillColor(TX_BLACK);
        txSetColor(TX_BLACK);
        txRectangle(MIN_X, MIN_Y, MAX_X, MAX_Y);
        txSelectFont("Arial", 120, 30, MAX_Y);
        txSetFillColor(TX_WHITE);
        if (!mouse)
        {
            txRectangle(300+xButton, 400+yButton, 700+xButton, 600+yButton);
            txSetFillColor(TX_BLACK);
            txSetColor(TX_BLACK);
            txDrawText(300+xButton, 450+yButton, 700+xButton, 550+yButton, "����������");
        }
        txSetColor(TX_WHITE);
        txSetFillColor(TX_WHITE);
        txSelectFont("Arial", 60, 20);
        if (!shift)
        {
            txDrawText(20, 70, MAX_X, 350, "������� � ��� �������� �� ����������. \n ��������� WASD �� ���������� ��� �������� ������");
        }
        if (shift and !mouse)
        {
            txDrawText(20, 70, MAX_X, 350, "���������, � ������ ������� ��������� ����������. \n ������� shift ��� ���������");
        }
        if (mouse)
        {
            txDrawText(20, 70, MAX_X, 350, "����� � ���� ����� �����������, ������� ���� ��������� � ������� �����. \n �������� ������ �� ����� �������, \n����� �� ���� ����� ���� ������");
            txDrawText(20, 700, MAX_X, 900, "�������� �� ��������, �� \n��� �������� ������ ������");
        }
        if (GetAsyncKeyState(0x41))
        {
            xButton = xButton - 5*acceleration;
            left = true;
        }
        if (GetAsyncKeyState(0x44))
        {
            xButton = xButton + 5*acceleration;
            right = true;
        }
        if (GetAsyncKeyState(0x57))
        {
            yButton = yButton - 5*acceleration;
            up = true;
        }
        if (GetAsyncKeyState(0x53))
        {
            yButton = yButton + 5*acceleration;
            down = true;
        }
        if (down and up and right and left)
        {
            shift = true;
        }
        if (GetAsyncKeyState(VK_SHIFT) and shift)
        {
            acceleration = 3;
            moveCheck = true;
        }
        else
        {
            acceleration = 1;
        }
        if (moveCheck)
        {
            moveCalc = moveCalc+1;
        }
        if (moveCalc==ACCELERATED_TIME)
        {
            mouse = true;
            moveCheck = false;
        }
        if (mouse)
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);
            if (txMouseX()>MIN_X and txMouseX()<350 and txMouseY()>350 and txMouseY()<650)
            {
                txSetFillColor(TX_BLACK);
                square = true;
            }
            else
            {
                if (square)
                {
                    training = false;
                }
            }
            txRectangle(MIN_X, 350, 350, 650);
            txSelectFont("Arial", 30, 10);
            txSetColor(TX_WHITE);
            txDrawText(2, 352, 342, 642, "���������! ������ �� ������ \n� ������� ����������. \n����� ����, ��� �� ������� \n������ ������ ���� �������� ����������. \n P.s.\n������ �������� �����");
        }
        txSleep(50);
        txClear();
    }
}
