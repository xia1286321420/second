//#include<iostream>
//#include<vector>
//#include<set>
//#include <unordered_set>
//#include<algorithm>
//#include<stack>
//#include<string>
//#include<queue>
//using namespace std;
//////***************************************面试题46把数字翻译成字符串
//////动态规划  关键找出公式  和开始边界；理解dp[0]为啥等于1；
//////动态规划 数组方法  
////int translateNum(int num) {
////    string si = to_string(num);
////    int length = si.length();
////    int dp[length+1];
////    dp[0] = 1;
////    dp[1] = 1;
////    for (int i = 2; i <= length; ++i)
////    {
//// //       int tmp = si[i] - '0' + si[i - 1] - '0';
//// //       if (tmp >= 10 && tmp <= 25)
////        string tmps = si.substr(i - 2, 2);
////        if(tmps<="25" && tmps>="10")
////            dp[i] = dp[i - 1] + dp[i - 2];
////        else
////        {
////            dp[i] = dp[i - 1];
////        }
////    }
////    return dp[length];
////}
             
////***************************************面试题45 把数组排成最小的数
////注意背后的数学验证
//string minNumber(vector<int>& nums) {
//    vector<string> vs;
//    for (int i = 0; i < nums.size(); ++i)
//        vs.push_back(to_string(nums[i]));
//    //lamda 表达式  重载compare；
//   // sort(vs.begin(), vs.end(), [](string& s1, string& s2) {return s1 + s2 < s2 + s1});看看少了什么；
//    sort(vs.begin(), vs.end(), [](string& s1, string& s2) {return s1 + s2 < s2 + s1; });
//    string res;
//    // for (vector<int>::iterator i = vs.begin(); i != vs.end(); ++i)  看看哪里错； 
//    for (vector<string>::iterator it = vs.begin(); it != vs.end(); ++it)
//        res += *it;
//    return res;
//}
////***************************************面试题29顺时针打印矩阵
//vector<int> spiralOrder(vector<vector<int>>& matrix) {
//    if (matrix.empty())return matrix;
//    vector<int> res;
//    //四个边界
//    int t = 0;
//    int b = matrix.size() - 1;
//    int l = 0;
//    int r = matrix[0].size() - 1;
//    //开始循环 四个方向依次遍历 模拟法
//    while (true)
//    {
//        for (int i = l; i <= r; ++i) res.push_back(matrix[t][i]);//左到右
//        if (++t > b)break;
//        for (int i = t; i <= b; ++i) res.push_back(matrix[i][r]);//上到下
//        if (--r > l)break;
//        for (int i = r; r >= l; --r) res.push_back(matrix[b][i]);//右到左
//        if (--b < t)break;
//        for (int i = b; i >= t; --i) res.push_back(matrix[i][l]);//下到上
//        if (++l > r)break;
//    }
//    return res;
//}
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////***************************************面试题28对称的二叉树
////迭代写法 用queue  也可以用栈
//bool isSymmetric(TreeNode* root) {
//    if (root == NULL) return true;
//    queue<TreeNode*> qt;
//    qt.push(root->left);
//    qt.push(root->right);
//    while (!qt.empty())
//    {
//        //   ListNode* tl = qt.front();//看看哪里错了
//        TreeNode* tl = qt.front();
//        qt.pop();
//        //    ListNode* tr = qt.front();
//        TreeNode* tr = qt.front();
//        qt.pop();
//        if (tl == NULL && tr == NULL) continue;
//        //continue都不存在就继续下一次循环 说明已经跳出来两个空的 不会继续压入空的 每个叶子应该都会压入空的 也就到头了。
//        if (tl == NULL || tr == NULL)return false;
//        if (tl->val != tr->val) return false;
//        qt.push(tl->left);
//        qt.push(tr->right);
//        qt.push(tl->right);
//        //        qt.push(tr->right);//看看哪里错了
//        qt.push(tr->left);
//    }
//    return true;
//}
//
//
////递归写法 
//bool  recIsSymmetric(TreeNode* rl, TreeNode* rr)
//{
//
//    if (rl == NULL && rr == NULL) return true;//都为空 
//    if (rl == NULL || rr == NULL) return false;//其一为空  
//    if (rl->val != rr->val) return false;
//    //return recIsSymmetric(rl->left, rl->right) && recIsSymmetric(rl->right, rl->left); 看出哪里写错了吗
//    return recIsSymmetric(rl->left, rr->right) && recIsSymmetric(rl->right, rr->left);
//}
//
//bool isSymmetric1(TreeNode* root) {
//    if (root == NULL) return true;
//    return  recIsSymmetric(root->left, root->right);
//}
//
////***************************************面试题27二叉树的镜像
////1 判断根的存在 2 跟存在后 子树存在不，都不存在返回  有一个存在就可以交换 ，交换之后再判定子树  递归下去；
////可以简化  
//TreeNode* mirrorTree1(TreeNode* root) {
//    if (root == nullptr) return root;
//    if (root->left == nullptr && root->right == nullptr) return root;
//    //swap
//    TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//    //左右子树遍历
//    if (root->left) mirrorTree1(root->left);
//    if (root->right)mirrorTree1(root->right);
//    return root;
//}
//
////简化版本  递归
//TreeNode* mirrorTree2(TreeNode* root) {
//    if (root == nullptr) return nullptr;
//
//    //swap
//    TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//    //左右子树遍历
//    mirrorTree2(root->left);
//    mirrorTree2(root->right);
//    return root;
//}
//// 栈的版本
//TreeNode* mirrorTree3(TreeNode* root) {
//    stack<TreeNode*> mirr;
//    if (root != nullptr) mirr.push(root);
//    while (!mirr.empty())
//    {
//        TreeNode* tmp = mirr.top();
//        //记得pop()啊
//        mirr.pop();
//        //swap
//        TreeNode* t = tmp->left;
//        tmp->left = tmp->right;
//        tmp->right = t;
//        if (tmp->right) mirr.push(tmp->right);//要if判定存在否
//        if (tmp->left) mirr.push(tmp->left);
//    }
//    return root;
//}
////队列的版本  和栈类似
//TreeNode* mirrorTree(TreeNode* root) {
//    queue<TreeNode*> mirr;
//    if (root != nullptr) mirr.push(root);
//    while (!mirr.empty())
//    {
//        TreeNode* tmp = mirr.front();
//        //记得pop()啊
//        mirr.pop();
//        //swap
//        TreeNode* t = tmp->left;
//        tmp->left = tmp->right;
//        tmp->right = t;
//        if (tmp->right) mirr.push(tmp->right);//要if判定存在否
//        if (tmp->left) mirr.push(tmp->left);
//    }
//    return root;
//}
//
////***************************************面试题26树的子结构
////递归方法 
////书上是double 类型所以不能直接相等 ，LeetCode是整型 可以直接==
//
//  //Definition for a binary tree node.
////struct TreeNode {
////    int val;
////    TreeNode* left;
////    TreeNode* right;
////    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
////};
//bool isSubStructure(TreeNode* A, TreeNode* B) {
//    bool flag = false;//相等标志位
//    if (A && B)
//    {
//        //如果相等  则继续判定此根下的子树
//        if (A->val == B->val) flag = DoesHaveSubtree(A, B);
//        if (!flag) flag = isSubStructure(A->left, B);//不成立就继续判断左子树
//        if (!flag) flag = isSubStructure(A->right, B);//还不成立判断右子树
//
//    }
//    //少了return
//    return flag;
//}
//bool DoesHaveSubtree(TreeNode* a, TreeNode* b)
//{
//    if (b == nullptr) return true; //如果b空了 则相等
//    if (a == nullptr)return false; //如果b非空a 空了 则错误   这俩顺序不能变  否则 当a,b 都空时 会返回错误 实际是对的
//    if (a->val != b->val)return false;//不相等则false
//    //都存在且相等则继续判断下面的子树
//    return  DoesHaveSubtree(a->left, b->left) && DoesHaveSubtree(a->right, b->right);
//}
//
////***************************************面试题25合并两个有序列表
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//    //自己的思路是
////迭代法
//    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
//        //ListNode* m = nullptr;
//        //ListNode** tmp = &m;
//          //借鉴别人的下面两行
//        ListNode* head = new ListNode(1);
//        ListNode* prehead = head;
//        while (l1 && l2)
//        {
//            if (l1->val < l2->val)
//            {
//                head->next = l1;
//                //head = head->next;//可以统一移出来
//                l1 = l1->next;
//            }
//            else
//            {
//                head->next = l2;
//                //head = head->next;//可以统一移出来
//                l2 = l2->next;
//            }
//            head = head->next;
//        }
//        if (l1 != NULL)  head->next = l1;
//        if (l2 != NULL) head->next = l2;
//
//        return prehead->next;
//    }
//    //递归法
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        if (l1 == nullptr)return l2;
//        if (l2 == nullptr)return l1;
//        ListNode* tmp = nullptr;
//        if (l1->val < l2->val)
//        {
//            tmp = l1;
//            tmp->next = mergeTwoLists(l1->next, l2);
//        }
//        else
//        {
//            tmp = l2;
//            tmp->next = mergeTwoLists(l1, l2->next);
//        }
//        return tmp;
//    }
////***************************************面试题24反转链表
////struct ListNode {
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(NULL) {}
////
////};
//ListNode* reverseList1(ListNode* head) {
//    if (head == nullptr) return head;
//    //三个指针 pre cur next 
//    ListNode* pre = nullptr;
//    ListNode* cur = head;
//    ListNode* next = head->next;
//    while (next)//下一个存在 cur是前一个
//    {
//        cur->next = pre;
//        pre = cur;
//        cur = next;
//        next = next->next;
//    }
//    return cur;
//}
////这个简洁 用这个
//ListNode* reverseList(ListNode* head) {
//    if (head == nullptr) return head;
//    //两个指针 pre cur next 
//    ListNode* pre = nullptr;
//    ListNode* cur = head;
//
//    while (cur)//下一个存在 cur是前一个
//    {
//        ListNode* tmp = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = tmp;
//    }
//    return pre;
//}
//
//////***************************************面试题23链表中环的入口点
//
////这题LeetCode 没有原题  找了环形链表这题 141  这个只是判断有无环 ，比较简单；
////快慢指针；
////struct ListNode {
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(NULL) {}
////
////};
//bool hasCycle(ListNode* head) {
//    if (head == nullptr || head->next == nullptr) return 0;//需要判定head->next吗?
//    ListNode* slow = head;
//    ListNode* fast = head->next;
//    while (slow != fast)//相等时推出  
//    {
//        if (fast == nullptr || fast->next == nullptr) //如果fast或者fast的下一个为空则返回错误  没有返回说明fast->next 也是有效的
//            return false;
//        slow = slow->next;//一个走一步一个走两步
//        fast = fast->next->next;
//    }
//    return true;
//}
//
//
//
//
//
//////******************面试题22链表中的倒数第k个节点
////struct ListNode {
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(NULL) {}
////
////};
////ListNode* getKthFromEnd(ListNode* head, int k) {
//    //我的思路 先把链表放入vector 第二个思路是放入栈 //这个思路只能求得数值  得不到指针  可以先先求得有多少个节点
//    //尝试1 错误  要看返回什么
//
////    vector<int> ivecSaveList;
////    while (head)
////    {
////        ivecSaveList.push_back(head->val);
////        head = head->next;
////    }
////    if(ivecSaveList.size()>k)
////
////}
//    //尝试2  遍历两次 的解法 一遍得节点数 一遍遍历到倒数第k个节点
////解法正确 效率不高  有一次遍历方法；
//ListNode* getKthFromEnd(ListNode* head, int k)
//{
//    // if(head==nullptr ) return head;
//    int cnt = 0;
//    ListNode* tmphead = head;
//    while (tmphead)
//    {
//        ++cnt;
//        tmphead = tmphead->next;//这里head=null了
//    }
//    int ck;
//    if (cnt >= k)//判断链表长度要大于k
//        ck = cnt - k + 1;
//    else return head;
//    while (ck > 1)//
//    {
//        // --cnt;//是----ck
//        --ck;
//        head = head->next;
//
//    }
//    return head;
//}
////更高效 的办法 一次遍历；  
////双指针  第一个走k-1步 然后第二个开始和第一个一起走，直到第二个走到头
//ListNode* getKthFromEnd(ListNode* head, int k)
//{
//    ListNode* p1 = head;
//    ListNode* p2 = head;
//    int gap = k - 1;
//    while (p2 && gap)
//    {
//        p2 = p2->next;
//        --gap;
//    }
//    while (p2 && p2->next)
//    {
//        p1 = p1->next;
//        p2 = p2->next;
//    }
//    return p1;
//}
//
//
//////******************面试题21调整数组顺序使奇数位位于偶数位前面
//
////快慢双指针 
//vector<int> exchange(vector<int>& nums) {
//    int low = 0, fast = 0;
//    while (fast < nums.size())
//    {
//        if ((nums[fast] & 1) == 1)
//        {
//            int  tmp = nums[low];
//            nums[low] = nums[fast];
//            nums[fast] = tmp;//swap
//            ++low;//low指针加一
//        }
//        //fast+1;
//        ++fast;
//    }
//    return nums;
//}
//
////双指针  
//vector<int> exchange1(vector<int>& nums) {
//    int pb = 0, pe = nums.size() - 1;
//    while (pb < pe)
//    {
//        while (pb < pe && (nums[pb] & 1) != 0)//奇数继续向后 直到遇到偶数  即nums[pb]& 1==0
//        {
//            ++pb;
//        }
//        while (pb < pe && (nums[pe] & 1) == 0)//偶数继续向前  直到遇到奇数
//        {
//            --pe;
//        }
//        if (pb < pe)
//        {
//            int tmp = nums[pb];
//            nums[pb] = nums[pe];
//            nums[pe] = tmp;
//        }
//    }
//    return nums;
//}
//////******************面试题20表示数值的字符串
//int pointer=0;
//bool   scanUInteger(string& s)
//{
//    int pstart = pointer;
//    while (pointer < s.length()  && s[pointer] >= '0' && s[pointer] <= '9') //没有到达最后的时候一直检查 
//    {
//        ++pointer;
//    }
//    return pointer > pstart;  
//
//}
//bool scanInteger(string& s)
//{
//    if (s[pointer] == '-' || s[pointer] == '+') ++pointer;//判断首字符是否为正负号
//    return scanUInteger(s);
//}
//void  delspace(string& s)
//{
//    while (s[pointer]==' ')
//    {
//        ++pointer;
//    }
//}
//bool isNumber(string s) {
//    if (s.empty())return false;
//    //加一个排除空格
//    delspace(s);
//    //先判断a
//    bool num = scanInteger(s);
//    //然后看后面是否是点
//    if (s[pointer] == '.')//忘了++pointer
//    {
//        ++pointer;
//        num =  scanUInteger(s) || num;//这个位置有讲究啊   或运算 前面的正确则不会运行后面的  但是如果没有运行后面的 则pointer 不会移到后面 会出错
//    }
//    //然后看是后面否是e
//    if (s[pointer] == 'e')//如果是e 判断后面是否是整数  而且e前面得有整数  也就是前面的num是true  如e12 .e2 等不是数字  ；  
//    {
//        ++pointer;//又忘了++pointer;
//        num = num && scanInteger(s);
//    }
//    delspace(s);//移出后面的空格
//    return (num && pointer == s.length()) ;// == 不是=
//}
//
//
//
//
////******************面试题19正则表达式匹配
////剑指offer解法
////bool isMatch1(string s, string p) {
////    if (p.empty()) return s.empty();
////    bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
////    if (p.length() >= 2 && p[1] == '*')//0次和n次// 先判断有没有p[]
////        return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
////    else
////        return first_match && isMatch(s.substr(1), p.substr(1));
////}
//
////下面答案有bug  如果匹配模式以 *结尾那么匹配模式非空 但是字符串能匹配完全
////bool rcMatch(string& s, string& p, int ptr,int str);
////bool isMatch1(string s, string p) {
////    if (s.empty() || p.empty())return false;
////    return rcMatch( s, p,0,0);
////}
////
////bool rcMatch(string& s, string& p,int str,int ptr)
////{
////    //终止条件
////    if (str != s.length() - 1 && ptr == p.length() - 1) return false; //没有匹配完
////    if (str == s.length() - 1 && ptr == p.length() - 1) return true;
////    //考虑第二个是否是‘*’ 
////    if (p[ptr + 1] == '*')
////    {
////        if (p[ptr] == s[str] || (p[ptr] == '.' && str != s.length()))
////        {
////            return rcMatch(s, p, str + 1, ptr + 2) || rcMatch(s, p, str + 1, ptr) || rcMatch(s, p, str, ptr + 2);
////        }
////        else
////        {
////            return rcMatch(s, p, str, ptr + 2);
////        }
////    }
////    else
////    {
////        if(p[ptr] == s[str] || (p[ptr] == '.' && str != s.length()))
////            return rcMatch(s,p,str+1,ptr+1);
////    }
////    return false;
////}
//
////******************面试题18删除链表重复的节点
////struct ListNode {
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(NULL) {}
////};
////
////ListNode* deleteDuplicates(ListNode* head) {
////  //  ListNode* sahead = head;//保留头部节点/这句不必要，因为head没变
////    ListNode* cur = head;
////    while (cur && cur->next)//当前和下一个节点 都存在
////    {
////        if (cur->val == cur->next->val)//如果相等
////        {
////            ListNode* tmp = cur->next;
////            cur->next = cur->next->next;
////            delete tmp;
////            tmp = nullptr;
////        }
////        else
////        {
////            cur = cur->next;
////        }
////    }
////    return head;
////}
//
//
////******************面试题18删除链表的节点
////  Definition for singly-linked list.
//
//  //struct ListNode {
//  //    int val;
//  //   ListNode *next;
//  //   ListNode(int x) : val(x), next(NULL) {}
//  //};
// 
//  //ListNode* deleteNode(ListNode* head, int val) {
//  //    ListNode*sahead = head;//记录头指针，返回时用
//  ////覆盖存在val的节点
//  //    while (head)
//  //    {
//  //        if (head->val == val)
//  //        {
//  //            if (head->next) {//判断是否是尾结点
//  //                head->val = head->next->val;//复制下一个节点
//  //                head->next = head->next->next;
//  //                return sahead;
//
//  //            }
//  //            else //如果不是  则从头遍历到尾
//  //            {
//  //                head = sahead;//要从头遍历
//
//  //                while (head->next->next)//遍历到倒数第二个
//  //                {
//  //                    head = head->next;
//  //                }
//  //                head->next = nullptr;
//  //                return sahead;
//
//  //            }
//  //        }
//  //        head = head->next;//又忘了迭代了
//  //    }
//  //    return sahead;
//  //}
//
////方法一
//  //ListNode* deleteNode1(ListNode* head, int val) {
//  //    if (head == nullptr) return head;
//  //    ListNode* sahead = head;
//  //    if (head->val == val)return head->next;//如果是头需要特殊对待一下，也有其他办法
//  //    while (head->next)
//  //    {
//  //        if (head->next->val == val)
//  //        {
//
//  //            head->next = head->next->next;
//  //            return sahead;
//  //        }
//  //        head = head->next;
//
//  //    }
//  //    return sahead;
//  //}
//
////*************************************************************面试题17打印从1到最大的n位数 
//
////模拟加法；
//
//
////主函数
////vector<int>ret;
////bool incrnum(string& res, int n);
////void printNumbers(int n) {
////    string res(n, '0');
////   
////    while (!incrnum)
////    {
////        printNum(res);
////    }
////}
////模仿加一
////bool incrnum(string& res, int n)
////{
////    bool overnum = false;
////    int takeover = 0;
////        for (int i = res.length() - 1; i >= 0; --i)
////        {
////            int tem = res[i] - '0' + takeover;
////            if (i == res.length() - 1) ++tem;
////            if (tem >= 10)
////            {
////                if (i == 0)//最后一位时 ，溢出
////                overnum = true;
////                else
////                {
////                    takeover = 1;
////                    tem -= 10;
////                    res[i] = '0' + tem; //不是最后一位时，减10，进位符合置一；
////                }
////            }
////            else
////            {
////                res[i] = '0' + tem;//么有进一则前面不变，退出循环
////                break;
////            }
////            return overnum;
////        }
////}
//////打印数字
////void printNum(string& s)//打印数字；
////{
////    bool fst = false;//判断第一个
////    string tmps = "";
////    for (int i = 0; i < s.length(); ++i)
////    {
////
////        if (!fst && s[i] != '0') //第一个不为零之后，fst==true , 开始打印之后的每一个；
////            fst = true;
////        if (fst)
////        {
////            tmps += s[i];//
////        }
////
////    }
////    if (!tmps.empty())//空字符串不能转换
////    {
////    int tmpi = stoi(tmps);//stoi 在string里面 
////     ret.push_back(tmpi);
////    }
////
////}
//
////这是简单写法 意义不大
////vector<int> printNumbers1(int n) {
////    vector<int> res;
////    int sum = pow(10, n);
////    for (int i = 1; i < sum; ++i)
////        res.push_back(i);//是push_back() 不是pushback();
////    return res;
////}
//
//
//
////递归大数写法；
//
////主函数
////vector<int>ret;
////void printNumbers(int n) {
////    string res(n, '0');
////   
////    dfsprint(res, 0);
////}
//////递归求解
////void dfsprint(string& s, int index)
////{
////    if (index = s.length() )
////    {
////        printNum(s);//记录下来
////        return;
////    }
////    for (int i = 0; i < 10; ++i)
////    {
////        s[index ] = i + '0';
////        dfsprint(s, index + 1);
////    }
////
////
////}
//////打印数字
////void printNum(string& s)//打印数字；
////{
////    bool fst = false;//判断第一个
////    string tmps = "";
////    for (int i = 0; i < s.length(); ++i)
////    {
////
////        if (!fst && s[i] != '0') //第一个不为零之后，fst==true , 开始打印之后的每一个；
////            fst = true;
////        if (fst)
////        {
////            tmps += s[i];//
////        }
////
////    }
////    if (!tmps.empty())//空字符串不能转换
////    {
////    int tmpi = stoi(tmps);//stoi 在string里面 
////     ret.push_back(tmpi);
////    }
////
////}
//
////*************************************************************面试题16数值的整数次方
//
//double myPow(double x, int n) {
//    double res = 1.0;
//    if (x == 0 && n < 0) return -1;
//    long num = n; //记录n,如果n是最小的负值，反过来没有int对应的数
//    if (n < 0)
//    {
//        x = 1 / x;
//        num = -n;//使n为正数；
//    }
//    while (num)
//    {
//        if (num & 1)//如果末尾是一 则加平方
//        {
//            res *= x; //第一位是2的零次方是一；
//            //x *= x;//错误 不应该在这里  每循环一次都要平方
//
//        }
//        x *= x;//应该在这
//    num=    num >> 1;//注意要赋值给num ； num>>1 错误；
//
//    }
//
//    return res;
//}
////class Solution {
////public:
////    int findRepeatNumber(vector<int>& nums) {
////        unordered_set <int> hash_set;
////        for (int i : nums)
////        {
////            if (hash_set.count(i) == 1)
////                return i;
////            else
////                hash_set.insert(i);
////        }
////        return 0;
////    }
////};
//
////int findRepeatNumber(vector<int>& nums) {
////    if (nums.size ()==0) return -1;
////    int start = 0;
////    int end = nums.size() - 1;
////    while (start < end)
////    {
////        int cnt = 0;
////        int middle = (end - start) / 2 + start;
////        //计算cnt   
////        for (int i = 0; i < nums.size(); ++i)
////        {
////           
////            if (nums[i] <= middle && nums[i]>=start)
////                cnt++;
////        }
////
////            if (cnt >= (middle + 1 - start))
////                end = middle;
////            else
////                start = middle + 1;
////
////    }
////  
////    return start;
////
////}
//
////int  CountNumbers(vector<int>& nums, int start, int end)
////{
////    int count = 0;
////        for (auto& s: nums)
////        {
////            if (s <= end && s >= start)
////                count++;
////        }
////        return count;
////}
//
//
////超出
//class Solution2 {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//        int row = 0;
//        int max_row = matrix.size() - 1;
//      
//        int column = matrix[0].size()-1;
//        bool flag = false;
//        while (row <= max_row && column >=0)
//        {
//            int i = matrix[row][column];
//            if (i == target)
//                flag = true;
//            else if (i > target)
//                --column;
//            else
//                ++row;
//        }
//        return flag;
//    }
//};
////*************************************************************面试题4二维数组
//
////书上解法
////class Solution1 {
////public:
////    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
////        if (matrix.empty() || matrix[0].empty()) {
////            return false;
////        }
////        int i = 0;//行
////        int j = matrix[0].size()-1;
////        //bool flag = false;
////        while ( j >=0 && i < matrix.size())
////          if (matrix[i][j] == target) return  true;
////            else if (matrix[i][j] > target)   --j;
////             else  ++i;
////            return false;
////    }
////};
//
/////暴力解法
//
////class Solution {
////public:
////    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
////        if (matrix.empty() || matrix[0].empty() )return false;
////        for (int i = 0; i < matrix.size(); ++i)
////        {
////            for (int j = 0; j < matrix[0].size(); ++j)
////            {
////                if (matrix[i][j] == target)
////                    return true;
////            }
////            return false;
////    }
////    }
////};
//
////*************************************************************面试题5替换空格
////string 解法
//string replaceSpace1(string s) {
//    int cnt = 0;
//    string s3 = {};
//    for (auto& iter : s)
//        if (iter == ' ') s3 += "%20";
//        else s3 += iter;
//    return s3;
//
//}
//
//string replaceSpace(string s) {
//    //原始长度
//    int len1 = s.length() - 1; 
//    for (int i = 0; i <= len1; ++i)
//        if (s[i] == ' ') s =s+ '0'+'0';
//    int len2 = s.length() - 1;//加00后的长度
//    if (len2 <= len1) return s; //没有空格就返回
//
//    //指定两个指针 一个是原始的  一个是加00的
//    while (len1>=0 && len2>len1)//第一个指针大于等于零 ，第二个指针要大于第一个指针
//    {
//        if (s[len1] == ' ') //如果等于空格  
//        {
//            s[len2--] = '0';
//            s[len2--] = '2';
//            s[len2--] = '%';
//        }
//        else//不是空格就复制
//        {
//            s[len2--] = s[len1];
//        }
//        len1--;  //指针一向前 一步
//    }
//    return s;
//}\
//
//
//
////*************************************************************面试题6从尾到头打印链表
//// struct ListNode {
////    int val;
////    ListNode* next;
////    ListNode(int x) : val(x), next(NULL) {}
////    
////};
//
////这个是反转法
////  vector<int> reversePrint1(ListNode* head) {
////      //if (head == NULL)  return ;//空指针则返回
////      vector<int> ivec(0);//从头到尾
////      vector<int> rivec(0);//从尾到头
////      while (head!=NULL)   
////      {
////          ivec.push_back(head->val);
////          head = head->next;
////      }
//////也可以用algorithm算法中的reverse反转ivec;
//////      reverse(ivec.begin(), ivec.end());
//////      return ivec;
////      for (int i = ivec.size() - 1; i >= 0; --i)
////          rivec.push_back(ivec[i]);
////      return rivec;
////}
//
////入栈法
//  //vector<int> reversePrint2(ListNode* head) {
//  //    stack<int> ista;
//  //    vector<int> ivec(0);
//  //    while (head!=nullptr)
//  //    {
//  //        ista.push(head->val);
//  //        head = head->next;//不要忘了
//  //    }
//  //    while (!ista.empty())
//  //    {
//  //        ivec.push_back(ista.top()); //注意是top
//  //        ista.pop();
//  //    }
//  //    return ivec;
//  //}
//
//  //递归方法 占用空间大
//  //class Solution {
//  //public:
//  //    vector<int> ivec;
//  //vector<int> reversePrint3(ListNode* head) {
//  //    if (head == NULL) return;
//  //     reversePrint(head->next);
//  //    ivec.push_back(head->val);
//  //    return ivec;
//  //}
//  //};
//
//  // 改变链表结构法
//          //方法4：改变链表结构
//  //vector<int> reversePrint(ListNode* head) {
//  //    //vector<int>ivec;
//  //    //ListNode* pre = nullptr;
//  //    //ListNode* next = head;
//  //    //ListNode* cur = head;
//  //    //while (cur) {
//  //    //    next = cur->next;//保存当前结点的下一个节点
//  //    //    cur->next = pre;//   反向改变指针
//  //    //    pre = cur;//更新前一个节点
//  //    //    cur = next;//更新当前结点
//  //    //}
//  //    //while (pre) {//上一个while循环结束后，pre指向新的链表头
//  //    //    ivec.push_back(pre->val);
//  //    //    pre = pre->next;
//  //    //}
//  //    //return ivec;
//
//
//
//  //    vector<int>ivec;
//  //    ListNode* pre = nullptr;
//  //    ListNode* cur = head;
//  //    ListNode* next = head;
//  //    while (cur)
//  //    {
//  //      //  ivec.push_back(cur->val);//cuole 现在还是正序
//  //        next = cur->next;
//  //        cur->next = pre;
//  //        pre = cur;
//  //        cur = next;
//  //    }
//  //    while (pre)
//  //    {
//  //        ivec.push_back(pre->val);
//  //        pre = pre->next;
//  //    }
//  //    return ivec;
//  //}
//
//
//  //*************************************************************面试题7重建二叉树
//
//  
////     Definition for a binary tree node.
//  //struct TreeNode {
//  //    int val;
//  //    TreeNode *left;
//  //    TreeNode *right;
//  //    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  //};
//
//
//
//
//      //TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//      //    return rucur(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
//      //}
//      //TreeNode* rucur(vector<int>::iterator prebeg, vector<int>::iterator preend, vector<int>::iterator inbeg, vector<int>::iterator inend)
//      //{
//      //    if (inend == inbeg) return nullptr;
//      //    TreeNode* cur = new TreeNode(*prebeg);//当前的根；
//      //    vector<int>::iterator mid = find(inbeg, inend, *prebeg);//在中序中找到根的位置
//      //    cur->left = rucur(prebeg + 1, prebeg + 1 + (mid - inbeg), inbeg, mid);//注意vector 区间前闭后开；
//      //    cur->right = rucur(prebeg + 1 + (mid - inbeg), preend, mid + 1, inend);
//      //    return cur;
//
//      //}
//
//
//      //*************************************************************面试题9 两个栈实现队列
//
//      //class CQueue {
//      //public:
//      //    stack<int> app;
//      //    stack<int> del;
//      //    CQueue() {
//      //        //记得清空栈 
//      //        while (!app.empty())
//      //        {
//      //            app.pop();
//      //        }
//      //        while (!del.empty())
//      //        {
//      //            del.pop();
//      //        }
//      //    }
//
//      //    void appendTail(int value) {
//      //        app.push(value);
//      //    }
//
//      //    int deleteHead() {
//      //        if (del.empty())//如果del栈空了  则把app放入；
//      //            while (!app.empty())
//      //            {
//      //                del.push(app.top());
//      //                app.pop();
//      //            }
//      //        if (del.empty()) return -1; //记得如果还是空 返回-1；
//      //        int i = del.top();
//      //        del.pop();
//      //        return i; //记得返回 
//      //    } 
//      //};
//
//      /**
//       * Your CQueue object will be instantiated and called as such:
//       * CQueue* obj = new CQueue();
//       * obj->appendTail(value);
//       * int param_2 = obj->deleteHead();
//      */
//
//      //*************************************************************面试题10 斐波那契
//      //动态规划  
//      //int fib1(int n) {
//      //    if (n < 2) return n;
//      //    vector<int> ivec(n+1,0);//注意是n+1个
//      //    ivec[0] = 0;
//      //    ivec[1] = 1;
//      //    for (int i = 2; i <= n; ++i)
//      //    {
//      //        ivec[i] = (ivec[i - 1] + ivec[i - 2])% 1000000007;//此处要%1000000007，不然会溢出
//      //    }
//      //    return ivec[n];
//      //}
//
////递归  会超出时间限制
//      //int fib(int n) {
//      //    if (n <= 0) return 0;
//      //    if (n <= 1) return 1;
//      //    return (fib(n - 1) + fib(n + 1))% 1000000007;
//      //}
//
//// 只用两个大小的数组和三个常数
//      //int fib11(int n) {
//      //    int i[2] = { 0,1 };
//      //    if (n < 2) return i[n];
//      //    int i1=0, i2=1, i3;
//      //    for (int x = 2; x <= n; ++x)
//      //    {
//      //        i3 = (i1 + i2) % 1000000007;//此处要%1000000007，不然会溢出
//      //        i1 = i2, i2 = i3;
//      //    }
//      //    return i3;
//      //}
//
//      //*************************************************************面试题10-2青蛙跳台阶
//      //int numWays(int n) {
//      //    if (n < 3)return n;
//      //    int n1 = 1, n2 = 2;
//      //    int n3 = 0;
//      //    for (int i = 2; i < n; ++i)
//      //    {
//      //        n3 = n1 + n2;
//      //        n1 = n2;
//      //        n2 = n3;
//      //    }
//      //    return n3;
//      //}
//
//      //*************************************************************面试题11旋转数组
//     //int findmin(vector<int>& numbers);//顺序查找最小值 
//     //int minArray(vector<int> & numbers) {
//     //    if (numbers.empty()) return -1;//如果空 返回-1；
//     //    int p1 = 0;
//     //    int p2 = numbers.size() - 1;
//     //    if (numbers[p1] < numbers[p2])  return numbers[p1];//如果第一个小于最后一个 说明未旋转，第一个就是最小的；
//     //    while (p2 > p1)//当等于一时 退出循环 返回p2;
//     //    {
//     //        int mid = (p1 + p2) / 2;
//     //        if (numbers[mid] == numbers[p2])
//     //            return findmin(numbers);
//     //        else if (numbers[mid] > numbers[p2]) p1 = mid + 1;
//     //        else  p2 = mid;
//     //    }
//     //    return numbers[p2];
//     //}
//     //int findmin(vector<int> & numbers)//顺序查找最小值
//     //{
//     //    int min = numbers[0];
//     //    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
//     //        if (min > * it) min = *it;
//     //    return min;
//     //}
//   
//
//
//
// //*************************************************************面试题12矩阵中的路径
//
//
//    //这种会超出时间限制 ，不知道为啥
// //    bool exist(vector<vector<char>>& board, string word) {
// //// 首行为什么没有判断 空，是否已经包含在程序中 ，需要理解
// //        for (int i = 0; i < board.size(); i++) {
//
// //            for (int j = 0; j < board[0].size(); j++)
// //            {
// //                if (dfs(board,word,i,j,0)) return true;
// //            }
// //        }
// //        return false;
// //    }
// //    bool dfs(vector<vector<char>>& board, string &word, int i, int j,int num )
// //    {
// //        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
// //            return false;
// //        if (board[i][j] != word[num])return false;
// //        //当num=word.length()-1 时，说明已经是最后一个了，然后前面没有返回说明board[i][j] == word[num] ，所以成立；
// //        if (num == word.length()-1)return true;
// //        char tmp = board[i][j];
// //        board[i][j] = '/';//替换掉 避免重复 ，
// //        int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
// //        for (int q = 0; q < 4; ++q)//原来是这里错了++m
// //        {
// //             //i = i + dx[q],j = j + dy[q];//原来这里不一样  int  i  int j  ,不用 i ，j 是因为冲突吗
// //            int m = i + dx[q], n = j + dy[q];
// //            if (dfs(board, word, m , j , num + 1))
// //               return true;
// //        }
// //        board[i][j] = tmp;
// //       return false;
// //    }
//
//
//
//  //bool exist(vector<vector<char>>& board, string word) {
//  //           for (int i = 0; i < board.size(); i++) {
//  //               for (int j = 0; j < board[0].size(); j++) {
//  //                   if (dfs(board, word, i, j, 0))
//  //                       return true;
//  //               }
//  //           }
//  //           return false;
//  //       }
//         //bool dfs(vector<vector<char>>& board, string& word, int i, int j, int num) {
//         //    if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[num])
//         //        return false;
//         //    if (num == word.length() - 1)
//         //        return true;
//         //    char temp = board[i][j];
//         //    board[i][j] = '/';
//         //    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
//         //    for (int q = 0; q < 4; q++) {
//         //        int m = i + dx[q], n = j + dy[q];
//         //        if (dfs(board, word, m, n, num + 1)) return true;
//         //    }
//         //    board[i][j] = temp;
//         //    return false;
//         //}
//
//
// //*************************************************************面试题12机器人的运动范围
//
//     //int dfs(int m ,int n ,int k ,int i,int j  , vector<vector<int>>& vi);
//     //bool s(int i, int j,int k);
//
//     //int movingCount(int m, int n, int k) {
//     //    vector<vector<int>> vis(m, vector<int>(n, 0));//访问标记
//     //    return dfs(m, n, k,0,0,vis);
//     //}
//
//     //int dfs(int m, int n, int k,int i,int j,vector<vector<int>> &vi) {
//     //    
//     //    if ( i>m  || j>n||vi[i][j]) return 0;//可达区域为三角形只能向下或者向右//i>.m 错了 还要等于
//     //    if (!s(i, j, k)) return 0;
//     //    vi[i][j] = 1;   
//     //    int cnt = 1  + dfs(m, n, k, i + 1, j,vi)  + dfs(m, n, k, i, j + 1,vi);
//     //    return cnt;
//     //}
//
//     //bool s(int m, int n,int k)//计算位数和
//     //{
//     //    int sum = 0;
//     //    while (m>0)
//     //    {
//     //        sum +=m % 10;
//     //      m= m / 10;
//     //    }
//     //    while (n > 0)
//     //    {
//     //        sum += n % 10;
//     //        n = n / 10;
//     //    }
//     //    return  sum<=k;
//     //}
//
//
//
//     //int movingCount(int m, int n, int k) {
//     //    vector<vector<int>> vis(m, vector<int>(n, 0));//访问标记
//     //    return dfs(m, n, k, 0, 0, vis);
//     //}
//
//     //int dfs(int m, int n, int k, int i, int j, vector<vector<int>>& vi) {
//     //    //i>= m  等于时就超了    
//     //    if (i >= m || j >= n || vi[i][j] || (i % 10 + i / 10 + j % 10 + j / 10) > k) return 0;
//     //    vi[i][j] = 1;//记录保证只加一次 ，和矩阵路线不一样 这个不用再清零；
//     //    int cnt = 1 + dfs(m, n, k, i + 1, j, vi) + dfs(m, n, k, i, j + 1, vi);//可达区域为三角形只能向下或者向右
//     //    return cnt;
//     //}
//
//
//     //*************************************************************面试题14剪绳子
//
//     int integerBreak(int n) {
//         if (n < 2) return 0;
//         if (n == 2) return 1;
//         if (n == 3) return 2;
//         vector<int> iv(n + 1, 0);
//         //因为划分为接近e=2.7的乘积为最大值；需要这个数学基础 伪装的动态规划；
//         iv[0] = 0, iv[1] = 1, iv[2] = 2, iv[3] = 3;
//         for (int i = 4; i <= n;++i)
//         {
//             int max = 0;
//             for (int j = 1; j <= (i / 2); ++j)  
//                 if (max < iv[j] * iv[i - j]) max = iv[j] * iv[i - j];
//             iv[i] = max;
//         }
//         return iv[n];
//     }
//
//     //贪婪算法 
//     //三种情况    n%3=0,1,2 
//
//     //int integerBreak(int n) {
//     //    if (n < 2) return 0;
//     //    if (n == 2) return 1;
//     //    if (n == 3) return 2;//本来最大是三 因为必须砍一刀 所以成了2；
//     //    int a = n % 3, b = n / 3;
//     //    int sum=1;
//     //    if(a==0 )
//     //        while (b>0)
//     //        {
//     //            sum *= 3;
//     //            --b;
//     //        }
//     //    else if(a==1)
//     //    {
//  
//     //        sum *=4/3;
//     //        
//     //    }
//     //    else
//     //    {
//     //        sum *= 2;  //a==2 
//     //    }
//     //    return sum;
//
//     //}
//
//     //动态规划 从后向前；
//     int max(int, int, int);
//     //int integerBreak(int n) {
//     //    vector<int> iv(n + 1, 0);
//     //    iv[0] = 0, iv[1] = 1, iv[2] = 1;
//     //    for(int i=2;i<=n;++i)
//     //    {
//     //        for (int j = 1; j <i ; ++j)
//     //        {
//     //            iv[i] = max(iv[i], (i - j) * iv[j], (i - j) * j);//从三者中找到最小的
//     //     }
//     //    }
//     //    return iv[n];
//     //}
//
//     int max(int m, int n, int k)
//     {
//         int tmp;
//         if (m < n)  tmp = n;
//         else tmp = m;
//         if (tmp < k) tmp = k;
//         return tmp;           
//    }
//
//
//
//     //动态规划 从后向前； 分成三种情况 只有尽量分成2 和3  才是最大值  依赖于数学分析
//
//    // 暂时没写\
//
//
//
// //*************************************************************面试题15二进制中1的个数
//
//     int hammingWeight(uint32_t n) {
//         unsigned int  a = 1;//用无符号数1 与n与 然后左移
//         int cnt = 0;
//         while (n)
//         {
//             n = n & (n - 1);
//              ++cnt;
//         }
//         return cnt;
//     }
//
//     //n&(n-1)  
//
//
