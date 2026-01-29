
#include <iostream>
#include <cstdlib> 
#include <windows.h>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

int Random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

struct st_GameInfo 
{
    string Final_Result = "";
    int Round = 0;
    string Q_Level = "";
    string Opp_Type = "";
    int Correct_Ans = 0;
    int Wrong_Ans = 0;

};
int Easy_Q()
{
    return Random(1, 10);
}
int Mid_Q()
{
    return Random(11, 50);
}
int Hard_Q()
{
    return Random(51, 100);
}
int Round()
{
    int x;
    while (true) {
        try {
            cout << "How Many Questions Do You Want? ";
            cin >> x;

            if (cin.fail()) {
                throw runtime_error("Invalid input");
            }

            return x; 
        }
        catch (...) {
            cout << "❌ Please enter a valid number only!\n";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }
    }

}
int question_level() {
    int x;
    cout << "enter the question level 1[easy] 2[mid] 3[hard] 4[Mix] ? ";
    cin >> x;
    return x;
}
int operation_type() {
    int x;
    cout << "Enter the operation Type 1[+] 2[-] 3[*] 4[/] 5[mix] ?" ;
    cin >> x;
    return x;
}
char operation(int op)
{
   
    
    char opp[4] = { '+','-','*','/' };
    if (op == 5) {
        return opp[Random(1,4) - 1];
    }
    return opp[op - 1];
}
string level(int lev) {
    string arr[3] = { "Easy" , "Medium" , "Hard" };
    
    return arr[lev - 1];
}
pair<int,int> generate_nums(int level) {
    int num1, num2;
    if (level == 4) level = Random(1, 3);
    if (level == 1) {
        num1 = Easy_Q();
        num2 = Easy_Q();
    }
    else if (level == 2)
    {
        num1 = Mid_Q();
        num2 = Mid_Q();
    }
    else if (level == 3)
    {
        num1 = Hard_Q();
        num2 = Hard_Q();
    }
    
    return { num1 , num2 };
}
pair<bool,int> validate(int num1, int num2, char op, int ans) {
    if (op == '+')
    {
        return { (num1 + num2) == ans, (num1 + num2) };
    }
    else if (op == '-')
    {
        return  { (num1 - num2) == ans, (num1 - num2) };

    }
    else if (op == '*')
    {
        return  { (num1 * num2) == ans, (num1 * num2) };
    }
    else if (op == '/')
    {
        return  { (num1 / num2) == ans, (num1 / num2) };
    }
    return { 0,0 };
}
void End_Game(st_GameInfo& info)
{
    cout << "*************************************************" << endl;
    cout << "______Round = " << info.Round << endl;
    cout << "______Final Result = " << info.Final_Result << endl;
    cout << "______Correct Answer : " << info.Correct_Ans << endl;
    cout << "______Wrong Answer : " << info.Wrong_Ans << endl;
    cout << "______operation_type : " << info.Opp_Type << endl;
    cout << "------Question Type  :  " << info.Q_Level << endl;
    cout << "*************************************************" << endl;


}
void Valid(bool ans, int correct_ans, st_GameInfo& info)
{
    if (ans == true)
    {
        info.Correct_Ans++;
        system("color 20");
        cout << "Correct Answer " << endl;
    }

    else {
        system("color 40");
        info.Wrong_Ans++;

        cout << "wrong answer \a " << endl;
        cout << "The correct answer is : " << correct_ans << endl;
    }
}
void Main_Screen()
{
    char turn = 'y';
    while (turn == 'Y' || turn == 'y')
    {
        st_GameInfo info;
        system("cls");
        system("color 07");
        int Rounds = Round();
        int Ql = question_level();
        int op = operation_type();
        info.Opp_Type= (op == 1 ? "+" :
            op == 2 ? "-" :
            op == 3 ? "*" :
            op == 4 ? "/" :
            op == 5 ? "Mix" : "?");
        info.Q_Level= (Ql == 1 ? "Easy" :
            Ql == 2 ? "Mid" :
            Ql == 3 ? "Hard" :
            Ql == 4 ? "Mix" : "Invalid");
        info.Round = Rounds;
        for (int i = 1; i <=Rounds; i++)
        { 
            char operat = operation(op);
            cout << "Question [" << i << "]\n";
            pair<int, int> nums = generate_nums(Ql);
            cout << nums.first << '\n' << nums.second << "  " << operat << endl;
            int ans; 
            cout << "--------" << endl;
            cin >> ans;
            pair<bool, int>val = validate(nums.first, nums.second, operat, ans);
            Valid(val.first, val.second,info);
           
            cout << "------------" << endl;
        }  
        if (info.Correct_Ans >= info.Wrong_Ans)
        {
            info.Final_Result = "Winner";
        }
        else {
            info.Final_Result = "Loose";
        }
        End_Game(info);

        cout << "Do you want play a gain y/n ";
        cin >> turn;
    }
} 
int main()
{
    srand((unsigned)time(NULL));
    Main_Screen();
    
}

