/*!
 * @file example-00b.c++
 *
 * @brief サンプルプログラム
 */

#include <iostream>
#include <string>

#include <sql++.h++>

/*!
 * @brief SELECT 文を可変オブジェクトとして構築する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace std::literals::string_literals;
    using namespace sqlxx;

    SelectStatement select_statement;

    SelectClause select_closure;
    FromClause   from_closure;
    WhereClause  where_closure;

    Column people_id_column;
    Column people_name_column;
    Table  people_table;

    AsClause people_id_as_clause;
    AsClause people_name_as_clause;
    AsClause people_as_clause;

    ConditionExpression condition_expression;
    GroupedExpression   grouped_expression;
    Identifier          people_name_identifier;
    Identifier          people_nick_name_identifier;

    people_id_as_clause.alias_name("p.id");
    people_name_as_clause.alias_name("p.name");
    people_as_clause.alias_name("p");

    people_id_column.name("id").as(people_id_as_clause);
    people_name_column.name("name").as(people_name_as_clause);
    people_table.name("people").as(people_as_clause);

    people_name_identifier.name("p.name");
    people_nick_name_identifier.name("p.nick_name");

    condition_expression =
        people_name_identifier.not_equal_to(people_nick_name_identifier);

    grouped_expression =
        people_name_identifier.not_equal_to("John Doe"s)
            .logical_or(people_name_identifier.not_equal_to("Jane Doe"s));

    condition_expression = condition_expression.logical_and(grouped_expression);

    select_closure.column_list({ people_id_column, people_name_column });
    from_closure.table(people_table);
    where_closure.condition_expression(condition_expression);

    select_statement.select(select_closure)
        .from(from_closure)
        .where(where_closure);
    ;

    std::cout << select_statement << std::endl;
}
