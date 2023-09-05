#include <iostream>
#include <vector>

class FindDuplicate
{
public:
    std::vector<int> FindDuplicateNumer(std::vector<int> numbers)
    {
        std::vector<int> duplicates;

        for (int i = 0; i < numbers.size(); i++)
        {
            int matches = 0;
            int matchindex = 0;
            for (int j = i; j < numbers.size(); j++)
            {
                if (numbers[i] == numbers[j])
                {
                    matches++;
                    matchindex = j;
                }
                if (matches > 1 && j == numbers.size() - 1)
                {
                    auto it = std::find(duplicates.begin(), duplicates.end(), numbers[matchindex]);
                    if (it == duplicates.end())
                        duplicates.push_back(numbers[matchindex]);
                }
            }
        }
        return duplicates;
    }
};

int main()
{

    FindDuplicate *obj = new FindDuplicate();

    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(20);
    numbers.push_back(40);
    numbers.push_back(40);
    numbers.push_back(20);
    numbers.push_back(40);
    numbers.push_back(40);

    std::vector<int> duplicates = obj->FindDuplicateNumer(numbers);

    return 0;
}