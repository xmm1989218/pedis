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
 *
 *  Copyright (c) 2006-2010, Peng Jian, pstack@163.com. All rights reserved.
 *
 */
#include "zset.hh"
#include "iterator.hh"
#include <functional>
#include <iomanip>
#include <cstring>
namespace redis {

struct zset::rep
{
    friend class zset;
    unsigned long _len;

    std::function<void(item* val)> _free_value_fn;
    rep() : _len(0) {}
    ~rep();
    long length() { return _len; }
};

zset::zset() : _rep(new zset::rep()) {}

zset::~zset()
{
    if (_rep != nullptr) {
        delete _rep;
    }
}

long zset::length()
{
    return _rep->length();
}

int zset::add(item* val, double score) {
  // TODO
}

int zset::count(double start, double end) {
  // TODO
}

int zset::incrby(item* val, double delta) {
  // TODO
}

std::vector<item_ptr> zset::range(int start, int end) {
  // TODO
}

std::vector<item_ptr> zset::rangebyscore(double start, double end) {
  // TODO
}

int zset::rank(item* val) {
  // TODO 
}

int zset::remove(item* val) {
  // TODO
}

int zset::removebyrank(int start, int end) {
  // TODO
}

int zset::removebyscore(double start, double end) {
  // TODO
}

double zset::score(item* val) {
  // TODO
}

}

