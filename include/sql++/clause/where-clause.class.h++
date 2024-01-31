/*!
 * @file where-clause.class.h++
 */

#ifndef SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_HXX
#define SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_HXX

#include <string>

#include <sql++/expression/condition-expression.class.h++>

namespace sqlxx
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief "WHERE 句" の文法クラス
     */
    class WhereClause
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        WhereClause();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] condition_expression "条件式" の文法オブジェクト
         */
        WhereClause(ConditionExpression condition_expression);

        /*!
         * @brief "条件式" を取得する
         *
         * @return "条件式" の文法オブジェクト
         */
        auto condition_expression() const -> ConditionExpression;

        /*!
         * @brief "条件式" を設定する
         *
         * @param[in] condition_expression "条件式" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto condition_expression(ConditionExpression condition_expression)
            -> WhereClause &;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を,
         *         そうではない場合は @c false を返却する
         */
        auto empty() const -> bool;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        /*!
         * @brief "条件式"
         */
        ConditionExpression _condition_expression;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out          出力ストリーム
     * @param[in] where_clause "WHERE 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, WhereClause const where_clause)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    WhereClause::WhereClause() : _condition_expression()
    {}

    WhereClause::WhereClause(ConditionExpression condition_expression)
        : _condition_expression(condition_expression)
    {}

    auto WhereClause::condition_expression() const -> ConditionExpression
    {
        return this->_condition_expression;
    }

    auto
    WhereClause::condition_expression(ConditionExpression condition_expression)
        -> WhereClause &
    {
        this->_condition_expression = condition_expression;
        return *this;
    }

    auto WhereClause::empty() const -> bool
    {
        return this->_condition_expression.empty();
    }

    auto WhereClause::to_string() const -> std::string
    {
        if (this->_condition_expression.empty()) {
            return "";
        }
        return "WHERE " + this->_condition_expression.to_string();
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, WhereClause const where_clause)
        -> std::ostream &
    {
        out << where_clause.to_string();
        return out;
    }
} // namespace clause
} // namespace sqlxx

#endif // SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_HXX
