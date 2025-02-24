type searchState struct {
  s string
  cost int
  distance int
  index int
}

func kSimilarity(s1 string, s2 string) int {
  n := len(s1)
  searchQueue := make([]*searchState, 1)
  searchQueue[0] = &searchState{s1, 0, heuristic(s1, s2), 0}
  for len(searchQueue) != 0 {
      state := searchQueue[0]
      if state.distance == 0 {
          return state.cost
      }

      searchQueue = searchQueue[1:]
      for state.index < n && state.s[state.index] == s2[state.index] {
          state.index++
      }

      for i := state.index + 1; i < n; i++ {
          if state.s[i] == s2[state.index] {
              s1Swap := swap(state.s, i, state.index)
              newState := searchState{s1Swap, state.cost + 1, heuristic(s1Swap, s2), state.index + 1}

              insertIndex, _ := sort.Find(len(searchQueue), func(i int) int {
                  if newState.cost + newState.distance > searchQueue[i].cost + searchQueue[i].distance {
                      return 1
                  } else {
                      return 0
                  }
              })

              if insertIndex < len(searchQueue) {
                  searchQueue = append(searchQueue[:insertIndex + 1], searchQueue[insertIndex:]...)
                  searchQueue[insertIndex] = &newState
              } else {
                  searchQueue = append(searchQueue, &newState)
              }
          }
      }
  }
  return len(s1)
}

func swap(s string, index1 int, index2 int) string {
  bytes := []byte(s)
  tmp := bytes[index1]
  bytes[index1] = bytes[index2]
  bytes[index2] = tmp
  return string(bytes)
}

func heuristic(s1 string, s2 string) int {
  count := 0
  for i := 0; i < len(s1); i++ {
      if s1[i] != s2[i] {
          count++
      }
  }
  return count / 2
}
