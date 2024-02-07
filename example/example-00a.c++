/*!
 * @file example-00a.c++
 *
 * @brief サンプルプログラム
 */

#include <iostream>
#include <string>

#include <sql++.h++>

/*!
 * @brief SELECT 文を不変オブジェクトとして構築する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace std::literals::string_literals;
    using namespace sqlxx;

    SelectStatement const select_statement {
        Select { { Column { "id", As { "p.id" } },
                   Column { "name", As { "p.name" } } } },
        From { Table { "people", As { "p" } } },
        Where {
            // clang-format off
            Identifier { "p.id" }.equal_to(1234)
            .logical_or(parentheses(
                Identifier { "p.name" }.equal_to("John Doe"s)
                .logical_or(Identifier { "p.name" }.equal_to("Jane Doe"s))
            ))
            // clang-format on
        }
    };

    std::cout << select_statement << std::endl;
}
