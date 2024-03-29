/*!
 * @file select-clause.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__SELECT_CLAUSE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__SELECT_CLAUSE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/clause/select-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>

#include "./data-set/select-clause-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__clause)

BOOST_AUTO_TEST_SUITE(class__SelectClause)

using sqlxx::ColumnIdentifier;
using sqlxx::SelectClause;
using sqlxx::test::SelectClauseDataSet;

/*!
 * @brief テストパターン :
 *        @c SelectClause オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::clause::SelectClause テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    SelectClause const source      = {}; // コピー元のオブジェクト
    SelectClause       destination = {   // コピー先のオブジェクト
        ColumnIdentifier { "p" }.as({ "p.id" }),
        ColumnIdentifier { "name" }.as({ "p.name" })
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
 *        様々な @c SelectClause オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::clause::SelectClause               テスト対象クラス
 * @see sqlxx::clause::SelectClause::empty()      テスト対象メンバ関数
 * @see SelectClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(SelectClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    SelectClause const select_clause = data_set_element.select_clause;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(select_clause.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c SelectClause オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::clause::SelectClause               テスト対象クラス
 * @see sqlxx::clause::SelectClause::to_string()  テスト対象メンバ関数
 * @see SelectClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(SelectClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    SelectClause const select_clause = data_set_element.select_clause;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(select_clause.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClause */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__clause */)

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__SELECT_CLAUSE_CLASS_TEST_CASE_HXX */
