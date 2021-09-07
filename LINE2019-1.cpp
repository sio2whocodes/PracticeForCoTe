//
//  main.cpp
//  PracticeForCodingTest
//
//  Created by 임수정 on 2021/09/07.
//

#include <iostream>
#include <queue>
using namespace std;

struct BCC{
    int c;
    int b;
    int cnt;
};

int main(){
    int C, B;
    cin >> C >> B;
    
    queue<BCC> q;
    BCC bcc = BCC();
    bcc.c = C;
    bcc.b = B;
    bcc.cnt = 0;
    
    q.push(bcc);
    
    bool isCatch = false;
    int result = 0;
    while(!q.empty()){
        BCC parent = q.front();
//        cout << parent.b << "," << parent.c << "," << parent.cnt << endl;
        q.pop();
        if(parent.c > 200000){
            continue;
        }
        if(parent.b == parent.c){
            result = parent.cnt;
            isCatch = true;
            break;
        }
        
        if(parent.b-1 >= 0 && parent.b-1 <= 200000){
            BCC next = BCC();
            next.b = parent.b-1;
            next.c = parent.c + parent.cnt+1;
            next.cnt = parent.cnt + 1;
            q.push(next);
        }
        
        if(parent.b+1 >= 0 && parent.b+1 <= 200000){
            BCC next = BCC();
            next.b = parent.b+1;
            next.c = parent.c + parent.cnt+1;
            next.cnt = parent.cnt + 1;
            q.push(next);
        }
        
        if(parent.b*2 >= 0 && parent.b*2 <= 200000){
            BCC next = BCC();
            next.b = parent.b*2;
            next.c = parent.c + parent.cnt+1;
            next.cnt = parent.cnt + 1;
            q.push(next);
        }
    }
    
    if(isCatch)
        cout << result;
    else
        cout << -1;
    return 0;
}
