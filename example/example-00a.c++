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
            IntegerLiteral { 1234 }.equal_to(Identifier { "p.id" })
            .logical_or(parentheses(
                Identifier { "p.name" }.equal_to("John Doe")
                .logical_or(Identifier { "p.name" }.equal_to("Jane Doe"))
            ))
            .logical_or(parentheses(
                Identifier { "p.birth_day" }.is(logical_not(null))
                .logical_and(Identifier { "p.birth_day" }.greater_equal("1901-01-01"s))
                .logical_and(Identifier { "p.birth_day" }.less_equal("2000-12-31"s))
            ))
            .logical_or(parentheses(
                Identifier { "p.longitude" }.greater_equal(122.5557)
                .logical_and(Identifier { "p.longitude" }.less_equal(153.5912))
                .logical_and(Identifier { "p.latitude" }.greater_equal(20.2531))
                .logical_and(Identifier { "p.latitude" }.less_equal(45.3326))
            ))
            .logical_and(Identifier { "p.has_deleted" }.not_equal_to(true))
            // clang-format on
        }
    };

    std::cout << select_statement << std::endl;
}
