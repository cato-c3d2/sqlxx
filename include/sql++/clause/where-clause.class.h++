/*!
 * @file where-clause.class.h++
 */

#ifndef SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_HXX
#define SQLXX__CLAUSE__WHERE_CLAUSE_CLASS_HXX

#include <stdexcept>
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
     * @brief ≪WHERE句≫を表現するクラス
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
         * @param[in] condition_expression ≪条件式≫のオブジェクト
         */
        WhereClause(ConditionExpression const & condition_expression);

        /*!
         * @brief デストラクタ
         */
        virtual ~WhereClause();

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        WhereClause(WhereClause const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(WhereClause const & origin) -> WhereClause &;

        /*!
         * @brief ≪条件式≫を取得する
         *
         * このオブジェクトが保持する≪条件式≫を複製し、そのポインタを返却する。
         *
         * @return 複製した≪条件式≫のポインタ
         */
        auto condition_expression() const -> ConditionExpression *;

        /*!
         * @brief ≪条件式≫を設定する
         *
         * 引数として指定した≪条件式≫を複製し、そのポインタをこのオブジェクトの≪条件式≫として保持する。
         *
         * @param[in] condition_expression ≪条件式≫
         *
         * @return このオブジェクトの参照
         */
        auto
        condition_expression(ConditionExpression const & condition_expression)
            -> WhereClause &;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を、
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
         * @brief このオブジェクトにコピー元のオブジェクトを割り当てる
         *
         * このオブジェクトの各データメンバに、
         * @c origin の各データメンバを代入する。 @n
         *
         * NOTE コピーコンストラクタとコピー代入演算子の実装を共通化するために実装した。
         *
         * @param[in] origin コピー元のオブジェクト
         */
        auto assignment(WhereClause const & origin) -> void;

    private:
        /*!
         * @brief ≪条件式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        ConditionExpression const * _condition_expression;
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
     * @param[in] where_clause ≪WHERE句≫のオブジェクト
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

    WhereClause::WhereClause() : _condition_expression(nullptr)
    {}

    WhereClause::WhereClause(ConditionExpression const & condition_expression)
        : _condition_expression(condition_expression.clone())
    {}

    WhereClause::~WhereClause()
    {
        if (this->_condition_expression != nullptr) {
            delete this->_condition_expression;
        }
    }

    WhereClause::WhereClause(WhereClause const & origin)
    {
        this->assignment(origin);
    }

    auto WhereClause::operator=(WhereClause const & origin) -> WhereClause &
    {
        this->assignment(origin);
        return *this;
    }

    auto WhereClause::condition_expression() const -> ConditionExpression *
    {
        return this->_condition_expression->clone();
    }

    auto WhereClause::condition_expression(
        ConditionExpression const & condition_expression) -> WhereClause &
    {
        this->_condition_expression = condition_expression.clone();
        return *this;
    }

    auto WhereClause::empty() const -> bool
    {
        if (this->_condition_expression == nullptr) {
            return true;
        }
        std::string condition_expression_as_string;
        try {
            condition_expression_as_string =
                this->_condition_expression->evaluate();
        } catch (std::runtime_error & e) {
            return true;
        }
        return condition_expression_as_string.empty();
    }

    auto WhereClause::to_string() const -> std::string
    {
        if (this->_condition_expression == nullptr) {
            return "";
        }
        std::string condition_expression_as_string;
        try {
            condition_expression_as_string =
                this->_condition_expression->evaluate();
        } catch (std::runtime_error & e) {
            return "";
        }
        return "WHERE " + condition_expression_as_string;
    }

    auto WhereClause::assignment(WhereClause const & origin) -> void
    {
        this->_condition_expression =
            (origin._condition_expression != nullptr)
                ? origin._condition_expression->clone()
                : nullptr;
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
