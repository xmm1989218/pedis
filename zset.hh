/*
 * This file is open source software, licensed to you under the terms
 * of the Apache License, Version 2.0 (the "License").  See the NOTICE file
 * distributed with this work for additional information regarding copyright
 * ownership.  You may not use this file except in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 *  Copyright (c) 2006-2010, Peng Jian, pstack@163.com. All rights reserved.
 *
 */
#pragma once
#include "core/stream.hh"
#include "core/memory.hh"
#include <boost/intrusive/list.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include "core/shared_ptr.hh"
#include "core/sharded.hh"
#include "base.hh"
#include <vector>
namespace redis {
class item;
using item_ptr = foreign_ptr<boost::intrusive_ptr<item>>;

class zset_iterator;

class zset : public object {
private:
    friend class zset_iterator;
    struct rep;
    rep* _rep;
public:
    zset();
    ~zset();
    long length();
    int add(item* val, double score);
    int count(double start, double end);
    int incrby(item* val, double delta);
    std::vector<item_ptr> range(int start, int end);
    std::vector<item_ptr> rangebyscore(double start, double end);
    int rank(item* val);
    int remove(item* val);
    int removebyrank(int start, int end);
    int removebyscore(double start, double end);
    double score(item* val);
};
}
