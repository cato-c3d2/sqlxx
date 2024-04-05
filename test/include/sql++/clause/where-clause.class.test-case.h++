/*!
 * @file where-clause.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>

#include "./data-set/where-clause-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__clause)

BOOST_AUTO_TEST_SUITE(class__WhereClause)

using sqlxx::ConditionExpression;
using sqlxx::IdentifierExpression;
using sqlxx::WhereClause;
using sqlxx::test::WhereClauseDataSet;

/*!
 * @brief テストパターン :
 *        @c WhereClause オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::clause::WhereClause テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    WhereClause const source      = {}; // コピー元のオブジェクト
    WhereClause       destination = {   // コピー先のオブジェクト
        ConditionExpression { IdentifierExpression { "p.id" }.equal_to(1234) }
    };
    // clang-format on

    // 二つのオブジェクトは等価ではないこと
    BOOST_CHECK(source.to_string() != destination.to_string());

    // コピー元のオブジェクトをコピー先のオブジェクトをコピー代入する
    destination = source;

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source.to_string() == destination.to_string());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        様々な @c WhereClause オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::clause::WhereClause               テスト対象クラス
 * @see sqlxx::clause::WhereClause::empty()      テスト対象メンバ関数
 * @see WhereClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(WhereClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    WhereClause const where_clause = data_set_element.where_clause;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果
    bool const actual = where_clause.empty();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c WhereClause オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::clause::WhereClause               テスト対象クラス
 * @see sqlxx::clause::WhereClause::to_string()  テスト対象メンバ関数
 * @see WhereClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(WhereClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    WhereClause const where_clause = data_set_element.where_clause;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果
    std::string const actual = where_clause.to_string();

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(actual, expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__WhereClause */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__clause */)

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_TEST_CASE_HXX */
