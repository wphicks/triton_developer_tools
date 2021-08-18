/*
 * Copyright (c) 2021, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <cstddef>
#include <string>
#include <vector>
#include <rapids_triton/tensor/tensor.hpp>
#include <rapids_triton/utils/narrow.hpp>

namespace triton { namespace backend { namespace rapids {
  /**
   * @brief Stores shared state for multiple instances of the same model
   */
  struct SharedModelState {
    virtual void load() {
    }
    virtual void unload() {
    }
  };

  template<typename SharedState=SharedModelState>
  struct Model {

    /* virtual void predict(Batch batch) {
     *   Fetch tensors in order and feed them to predict overload
     * };
     */

    private:
      std::shared_ptr<SharedState> shared_state;
  };
}}}  // namespace triton::backend::rapids
