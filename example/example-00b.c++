/*!
 * @file example-00b.c++
 *
 * @brief サンプルプログラム
 */

#include <sql++.h++>

#include <iostream>

/*!
 * @brief SELECT 文を可変オブジェクトとして構築する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace sqlxx::identifier;
    using namespace sqlxx::closure;
    using namespace sqlxx::statement;

    SelectStatement select_statement;

    SelectClosure select_closure;
    FromClosure   from_closure;

    Column people_id_column;
    Column people_name_column;
    Table  people_table;

    people_id_column.column_name("id").alias_name("p.id");
    people_name_column.column_name("name").alias_name("p.name");
    people_table.table_name("people").alias_name("p");

    select_closure.column_list({ people_id_column, people_name_column });
    from_closure.table(people_table);

    select_statement.select(select_closure).from(from_closure);

    std::cout << select_statement << std::endl;
}
