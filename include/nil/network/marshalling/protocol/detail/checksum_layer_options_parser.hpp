//---------------------------------------------------------------------------//
// Copyright (c) 2017-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef NETWORK_MARSHALLING_CHECKSUM_LAYER_OPTIONS_PARSER_HPP
#define NETWORK_MARSHALLING_CHECKSUM_LAYER_OPTIONS_PARSER_HPP

#include <nil/network/marshalling/options.hpp>

namespace nil {
    namespace marshalling {

        namespace protocol {

            namespace detail {

                template<typename... TOptions>
                class checksum_layer_options_parser;

                template<>
                class checksum_layer_options_parser<> {
                public:
                    static const bool has_verify_before_read = false;
                };

                template<typename... TOptions>
                class checksum_layer_options_parser<nil::marshalling::option::checksum_layer_verify_before_read,
                                                    TOptions...> : public checksum_layer_options_parser<TOptions...> {
                public:
                    static const bool has_verify_before_read = true;
                };

                template<typename... TOptions>
                class checksum_layer_options_parser<nil::marshalling::option::empty_option, TOptions...>
                    : public checksum_layer_options_parser<TOptions...> { };

                template<typename... TBundledOptions, typename... TOptions>
                class checksum_layer_options_parser<std::tuple<TBundledOptions...>, TOptions...>
                    : public checksum_layer_options_parser<TBundledOptions..., TOptions...> { };

            }    // namespace detail

        }    // namespace protocol

    }    // namespace marshalling
}    // namespace nil
#endif    // NETWORK_MARSHALLING_CHECKSUM_LAYER_OPTIONS_PARSER_HPP
