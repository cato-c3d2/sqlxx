/*!
 * @file operation-kind.enum-class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__OPERATION_KIND_ENUM_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__OPERATION_KIND_ENUM_CLASS_HXX

#include <string>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 演算子の種類
     */
    enum class OperationKind
    {
        /**
         * @brief 未定
         *
         * 演算子の種類が未定である場合等に使用する。
         */
        None = 0,

        /**
         * @brief 等値比較演算子
         */
        EqualTo,

        /**
         * @brief 非等値比較演算子
         */
        NotEqualTo,

        /**
         * @brief 比較演算子（小なり）
         */
        Less,

        /**
         * @brief 比較演算子（以下）
         */
        LessEqual,

        /**
         * @brief 比較演算子（大なり）
         */
        Greater,

        /**
         * @brief 比較演算子（以上）
         */
        GreaterEqual,

        /**
         * @brief 論理否定演算子
         */
        LogicalNot,

        /**
         * @brief 論理積演算子
         */
        LogicalAnd,

        /**
         * @brief 論理和演算子
         */
        LogicalOr,

        /**
         * @brief IS 演算子
         */
        Is,
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /**
     * @brief 演算子の文字列表現を返却する
     *
     * @param[in] operation_type 文字列に変換する演算子
     *
     * @return @c operation_type の文字列表現
     */
    auto to_string(OperationKind operation_type) -> std::string;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    inline namespace
    {
        /*!
         * @brief 各種演算子の文字列表現を定義するクラス
         *
         * 各種演算子の文字列表現は
         * @c sqlxx::expression::to_string(OperationKind)
         * を使用して取得する想定のため、このクラスは外部に公開しない。 @n
         * （そのために無名名前空間内に定義している。） @n
         */
        class OperatorSymbol
        {
        public:
            /**
             * @brief 等値比較演算子の記号
             */
            static constexpr auto EQUAL_TO = "=";

            /**
             * @brief 非等値比較演算子の記号
             */
            static constexpr auto NOT_EQUAL_TO = "<>";

            /**
             * @brief 比較演算子（小なり）の記号
             */
            static constexpr auto LESS = "<";

            /**
             * @brief 比較演算子（以下）の記号
             */
            static constexpr auto LESS_EQUAL = "<=";

            /**
             * @brief 比較演算子（大なり）の記号
             */
            static constexpr auto GREATER = ">";

            /**
             * @brief 比較演算子（以上）の記号
             */
            static constexpr auto GREATER_EQUAL = ">=";

            /**
             * @brief 論理否定演算子のキーワード
             */
            static constexpr auto LOGICAL_NOT = "NOT";

            /**
             * @brief 論理積演算子のキーワード
             */
            static constexpr auto LOGICAL_AND = "AND";

            /**
             * @brief 論理和演算子のキーワード
             */
            static constexpr auto LOGICAL_OR = "OR";

            /**
             * @brief IS 演算子のキーワード
             */
            static constexpr auto IS = "IS";
        };
    } // namespace

    auto to_string(OperationKind operation_type) -> std::string
    {
        switch (operation_type) {
        case OperationKind::EqualTo:
            return OperatorSymbol::EQUAL_TO;
        case OperationKind::NotEqualTo:
            return OperatorSymbol::NOT_EQUAL_TO;
        case OperationKind::Less:
            return OperatorSymbol::LESS;
        case OperationKind::LessEqual:
            return OperatorSymbol::LESS_EQUAL;
        case OperationKind::Greater:
            return OperatorSymbol::GREATER;
        case OperationKind::GreaterEqual:
            return OperatorSymbol::GREATER_EQUAL;
        case OperationKind::LogicalNot:
            return OperatorSymbol::LOGICAL_NOT;
        case OperationKind::LogicalAnd:
            return OperatorSymbol::LOGICAL_AND;
        case OperationKind::LogicalOr:
            return OperatorSymbol::LOGICAL_OR;
        case OperationKind::Is:
            return OperatorSymbol::IS;
        case OperationKind::None:
        default:
            return "";
        }
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__OPERATION_KIND_ENUM_CLASS_HXX
