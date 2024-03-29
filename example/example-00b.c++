/*!
 * @file example-00b.c++
 *
 * @brief サンプルプログラム
 */

#include <iostream>

#include <sql++.h++>

/*!
 * @brief SELECT 文を可変オブジェクトとして構築する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace sqlxx;

    SelectStatement select_statement;

    SelectClause select_closure;
    FromClause   from_closure;

    Column people_id_column;
    Column people_name_column;
    Table  people_table;

    AsClause people_id_alias;
    AsClause people_name_alias;
    AsClause people_alias;

    people_id_alias.alias_name("p.id");
    people_name_alias.alias_name("p.name");
    people_alias.alias_name("p");

    people_id_column.name("id").as(people_id_alias);
    people_name_column.name("name").as(people_name_alias);

    people_table.name("people").as(people_alias);

    select_closure.column_list({ people_id_column, people_name_column });
    from_closure.table(people_table);

    select_statement.select(select_closure).from(from_closure);

    std::cout << select_statement << std::endl;
}
