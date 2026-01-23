#include "Person.h"
#include "Company.h"
#include <iostream>
#include <memory>

using namespace std;

void testNormalCase() {
    cout << "\n========== 测试正常情况 ==========" << endl;
    {
        auto company = make_shared<Company>("科技公司");
        auto alice = make_shared<Person>("Alice", 28);
        auto bob = make_shared<Person>("Bob", 32);
        
        company->addEmployee(alice);
        company->addEmployee(bob);
        
        cout << "\n员工信息:" << endl;
        alice->showInfo();
        bob->showInfo();
        
        company->showEmployees();
        
        cout << "\nCompany 引用计数: " << company.use_count() << endl;
        cout << "Alice 引用计数: " << alice.use_count() << endl;
        cout << "Bob 引用计数: " << bob.use_count() << endl;
        
    }  // 作用域结束，所有对象正常销毁
    cout << "\n所有对象已正常销毁" << endl;
}

void testCompanyDestroyed() {
    cout << "\n========== 测试公司先销毁的情况 ==========" << endl;
    
    shared_ptr<Person> alice;
    {
        auto company = make_shared<Company>("创业公司");
        alice = make_shared<Person>("Alice", 28);
        
        company->addEmployee(alice);
        alice->showInfo();
        
    }  // company 被销毁
    
    cout << "\n公司已销毁，员工仍存在:" << endl;
    alice->showInfo();  // weak_ptr 已失效，显示"公司: 无"
}

int main() {
    testNormalCase();
    testCompanyDestroyed();
    
    cout << "\n程序结束" << endl;
    return 0;
}