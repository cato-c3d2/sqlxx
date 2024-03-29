/*!
 * @file as-clause.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__AS_CLAUSE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__AS_CLAUSE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/clause/as-clause.class.h++>

#include "./data-set/as-clause-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__clause)

BOOST_AUTO_TEST_SUITE(class__AsClause)

using sqlxx::AsClause;
using sqlxx::test::AsClauseDataSet;

/*!
 * @brief テストパターン :
 *        @c AsClause オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::clause::AsClause テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    AsClause const source      = {};         // コピー元のオブジェクト
    AsClause       destination = { "p.id" }; // コピー先のオブジェクト
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
 *        様々な @c AsClause オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::clause::AsClause               テスト対象クラス
 * @see sqlxx::clause::AsClause::empty()      テスト対象メンバ関数
 * @see AsClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(AsClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    AsClause const as_clause = data_set_element.as_clause;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(as_clause.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c AsClause オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::clause::AsClause               テスト対象クラス
 * @see sqlxx::clause::AsClause::to_string()  テスト対象メンバ関数
 * @see AsClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(AsClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    AsClause const as_clause = data_set_element.as_clause;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(as_clause.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__AsClause */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__clause */)

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__AS_CLAUSE_CLASS_TEST_CASE_HXX */
