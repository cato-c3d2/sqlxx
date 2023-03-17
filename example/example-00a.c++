/*!
 * @file example-00a.c++
 *
 * @brief サンプルプログラム
 */

#include <sql++.h++>

#include <iostream>

/*!
 * @brief SELECT 文を不変オブジェクトとして構築する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace sqlxx::identifier;
    using namespace sqlxx::closure;
    using namespace sqlxx::statement;

    SelectStatement const select_statement {
        Select { { Column { "id", As { "p.id" } },
                   Column { "name", As { "p.name" } } } },
        From { Table { "people", As { "p" } } }
    };

    std::cout << select_statement << std::endl;
}
