#include <iostream>
#include <random>
#include <ctime>   // 记得包含这个头文件
using namespace std;

int get_random_num(int min, int max)
{
    // static 保证只在第一次调用时初始化，后续复用
    static mt19937 gen(static_cast<unsigned>(time(0))); 
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
int main()
{
    int day;  // 定义在循环外，便于循环结束后判断

    for (day = 1; day <= 30; day++)
    {
        int num1 = get_random_num(1, 10);
        int num2 = get_random_num(1, 10);
        int num3 = get_random_num(1, 10);

        cout << "你喜欢小美，于是决定实施一个表白计划！" << endl;
        cout << "今天是你表白的第" << day << "天，";
        cout << "向小美送花。" << endl;

        if (num1 == 1)
        {
            cout << "不好！小美感到愤怒！" << endl;
            cout << "这下你的表白计划彻底泡汤了。" << endl;
            break;   // 彻底失败，跳出循环
        }
        else if (num1 > 5)
        {
            cout << "小美有些不高兴！" << endl;
            cout << "你的表白计划暂时告一段落。" << endl;
            cout << "你有些气馁，决定明天再进行你的计划。" << endl;
            continue;   // 明天继续
        }
        else   // num1 2~5
        {
            cout << "哇哦，小美接受了你的花！" << endl;
            cout << "你的表白计划成功了一部分！" << endl;
            cout << "于是乎，你决定邀请小美去看电影。" << endl;

            if (num2 < 6)
            {
                cout << "可是，小美不想去看电影。" << endl;
                cout << "你的表白计划暂时告一段落。" << endl;
                cout << "你有些气馁，决定明天再进行你的计划。" << endl;
                continue;
            }
            else   // num2 >= 6，同意看电影
            {
                cout << "小美接受了你的邀请，YES!" << endl;
                cout << "对小美说喜欢" << endl;

                // 现在处理表白环节（嵌套在内层 else 中，逻辑更清晰）
                if (num3 < 6)
                {
                    cout << "真可惜，小美并没有接受你的表白。" << endl;
                    cout << "你的表白计划暂时告一段落。" << endl;
                    cout << "你有些气馁，决定明天再进行你的计划。" << endl;
                    continue;
                }
                else   // num3 >= 6，表白成功
                {
                    cout << "小美很开心，接受了你的表白！" << endl;
                    cout << "恭喜你，你的表白计划成功了！" << endl;
                    break;   // 成功，跳出循环
                }
            }
        }
    }

    // 循环结束后判断：如果 day > 30，说明30天全部用完且没有提前 break
    if (day > 30)
    {
        cout << "30天过去了，你的计划失败了。" << endl;
    }

    return 0;
}
