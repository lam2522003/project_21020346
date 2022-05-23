#include "myGame.h" 
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    game Game;
    int Maxscore=0 ;
    srand(time(0));
    while(!Game.isQuit())
    {
        if (Game.isLost())
        {
            if (Game.getCountedFrame() > 0) {
                Game.Sound.playChord();
            }
            std::string t = "Click or press space to start!" ;
            Game.UserInput.Type = game::input::NONE;
            Game.LoadText(t);
            if(Game.Score()>Maxscore) Maxscore=Game.Score();
            Game.renderMaxScore(Maxscore);
            while(Game.isLost() && !Game.isQuit())
            {
                Game.takeInput();
                if (Game.UserInput.Type == game::input::CLICK)
                {
                    if (!Game.Sound.clickIconSpeaker())
                        Game.Restart();
                    Game.UserInput.Type = game::input::NONE;
                }
                Game.Background.render();
                Game.Pile.render();
                Game.Bird.render();
                Game.renderText();
                Game.renderScore();
                Game.renderMaxScore(Maxscore);
                Game.Sound.renderSpeaker();
                Game.FallingLeaf.render();
                Game.FallingLeaf.update();
                Game.display();
                Game.Sound.playWhistlingBird();
            }
            Game.Pile.PilePosition();
            Game.Pile.init();
            Game.Bird.init();
        }
        else
        {
            Game.takeInput();
            switch (Game.UserInput.Type)
            {
            case game::input::CLICK:
                if (!Game.Sound.clickIconSpeaker())
                {
                   Game.Sound.playSound();
                    Game.Bird.resetTime();
                }
                Game.UserInput.Type = game::input::NONE;
                break;
            }
            Game.Background.render();
            Game.Pile.render();
            Game.Bird.render();
            Game.renderScore();
            Game.FallingLeaf.render();
            Game.Sound.renderSpeaker();
            Game.display();
            Game.Bird.updateState();
            Game.Bird.update(Game.getPileWidth(), Game.getPileHeight());
            Game.Pile.update();
            Game.Background.update();
            Game.FallingLeaf.update();
            Game.Sound.playWhistlingBird();
        }
    }

    return 0;
}
