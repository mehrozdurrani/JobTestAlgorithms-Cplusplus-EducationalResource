#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_FRAMES = 10;

class Frame
{
private:
    int Roll1;
    int Roll2;

public:
    void SetRoll1(int _rollScore)
    {
        Roll1 = _rollScore;
    }

    void SetRoll2(int _rollScore)
    {
        Roll2 = _rollScore;
    }

    int GetRoll1Score()
    {
        return Roll1;
    }

    int GetRoll2Score()
    {
        return Roll2;
    }

    bool IsFrameStrike()
    {
        if (Roll1 == 10)
        {
            return true;
        }
        return false;
    }

    bool IsFrameSpare()
    {
        if (Roll1 + Roll2 == 10)
        {
            return true;
        }
        return false;
    }
};

int GetGameScore(vector<Frame> _frames)
{
    int score = 0;
    for (int i = 0; i < NUM_FRAMES; i++)
    {
        // Check Strike
        if (_frames[i].IsFrameStrike())
        {
            score += 10 + _frames[i + 1].GetRoll1Score() + _frames[i + 1].GetRoll2Score();

            // Double Strike
            if (_frames[i + 1].IsFrameStrike())
                score += _frames[i + 2].GetRoll1Score();
        }
        // Check Spare
        else if (_frames[i].IsFrameSpare())
        {
            score += 10 + _frames[i + 1].GetRoll1Score();
        }
        else
        {
            score += _frames[i].GetRoll1Score() + _frames[i].GetRoll2Score();
        }
    }
    return score;
}

int main()
{
    vector<Frame> frames;
    srand(static_cast<unsigned>(time(0)));
    cout << " ***** BOWLING SCORE CALCULATOR *****" << endl;
    int roll1 = 0;
    int roll2 = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
    {
        Frame frame;
        cout << "Frame " << i + 1 << " ";
        cout << "Roll 1: ";
        roll1 = rand() % 11;
        cout << roll1 << endl;
        frame.SetRoll1(roll1);

        if (roll1 < 10)
        {
            cout << "Frame " << i + 1 << " ";
            cout << "Roll 2: ";
            roll2 = rand() % (11 - roll1);
            cout << roll2 << endl;
            frame.SetRoll2(roll2);
        }
        else
            frame.SetRoll2(0);

        frames.push_back(frame);
    }

    cout << "The Player Score is : " << GetGameScore(frames);
    return 0;
}
