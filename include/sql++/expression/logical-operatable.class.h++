/*!
 * @file logical-operatable.class.h++
 */

#ifndef SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_HXX
#define SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_HXX

#include <string>

#include <sql++/expression/expression.class.h++>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 式オブジェクトの論理演算子の機能を提供するクラス
     *
     * NOTE 相互参照によるコンパイルエラーを避けるために、
     *      @c ConditionExpression を型パラメータとして受け取るように実装している。 @n
     */
    template<typename ConditionExpressionType>
    class LogicalOperatable : public virtual Expression
    {
    public:
        /*!
         * @brief 論理積演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、論理積演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::logical_and （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺の条件式
         *
         * @return 論理積演算式
         */
        auto logical_and(Expression const & operand) const
            -> ConditionExpressionType const;

        /*!
         * @brief 論理和演算式を生成する
         *
         * このオブジェクトを左辺の式、
         * @c operand を右辺の式とした、論理和演算式を生成する。 @n
         *
         * このメンバ関数の名称は、標準ライブラリ関数
         * @c std::logical_or （ @c \<functional\> ）を参考に命名した。 @n
         *
         * @param[in] operand 右辺値の条件式
         *
         * @return 論理和演算式
         */
        auto logical_or(Expression const & operand) const
            -> ConditionExpressionType const;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    template<typename ConditionExpressionType>
    auto LogicalOperatable<ConditionExpressionType>::logical_and(
        Expression const & operand) const -> ConditionExpressionType const
    {
        return ConditionExpressionType { "AND",
                                         this->clone(),
                                         operand.clone() };
    }

    template<typename ConditionExpressionType>
    auto LogicalOperatable<ConditionExpressionType>::logical_or(
        Expression const & operand) const -> ConditionExpressionType const
    {
        return ConditionExpressionType { "OR", this->clone(), operand.clone() };
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__LOGICAL_OPERATABLE_CLASS_HXX
