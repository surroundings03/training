// 原错误1（数字判断）：使用整数 0 和 9 作为范围，
// 无法匹配字符 '0'～'9'，应改为 '0' 和 '9'。

// 原错误2（长度判断）：使用 <= 10，
// 实际要求密码长度至少为 10，应改为 >= 10。

// 原错误3（范围边界）：使用严格不等号 <，
// 会遗漏 A、Z、a、z、0、9 等边界字符，
// 应改为 <=，包含范围两端。

// 自设计测试：
// 输入：Chen Luo Z0a1234567
// 预期输出：VALID
// 原因：长度为 10，包含大写、小写、数字，且不含姓名。

// 输入：Chen Luo Z0a123456
// 预期输出：INVALID
// 原因：密码长度只有 9。

#include <iostream>
#include <string>

bool contains_between(const std::string& text, char lower, char upper) {
    for (char ch : text) {
        if (lower <= ch && ch <= upper) {
            return true;
        }
    }
    return false;
}

bool check_password(const std::string& first_name,
                    const std::string& last_name,
                    const std::string& password) {
    bool length_ok = password.size() >= 10;
    bool upper_ok = contains_between(password, 'A', 'Z');
    bool lower_ok = contains_between(password, 'a', 'z');
    bool digit_ok = contains_between(password, '0', '9');
    bool name_ok = password.find(first_name) == std::string::npos &&
                   password.find(last_name) == std::string::npos;
    return length_ok && upper_ok && lower_ok && digit_ok && name_ok;
}

int main() {
    std::string first_name, last_name, password;
    if (!(std::cin >> first_name >> last_name >> password)) {
        std::cerr << "请输入：名 姓 密码\n";
        return 1;
    }
    std::cout << (check_password(first_name, last_name, password)
                      ? "VALID" : "INVALID") << '\n';
    return 0;
}
