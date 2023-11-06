# XMLResource

## Description
1. **`void Save(const std::string& path)`**:
   - Returns: `void` (no return value).
   - Description: Saves the current state of the XML resource to a file specified by the `path`. It writes the XML data to the file.

2. **`void Load(const std::string& path)`**:
   - Returns: `void` (no return value).
   - Description: Loads an XML resource from the file specified by the `path`. The XML data in the file is parsed and added to the existing resource.

3. **`iterator Add(const std::string& tag, const int& value, const iterator& parent)`**:
   - Returns: An iterator pointing to the newly added `XMLElement`.
   - Description: Adds a new `XMLElement` to the resource with the provided `tag`, `value`, and a specified `parent` iterator. The method returns an iterator pointing to the newly created element.

4. **`iterator Find(const int& val)`**:
   - Returns: An iterator pointing to the `XMLElement` with the specified `value`.
   - Description: Searches for an `XMLElement` within the resource that has the given `value` and returns an iterator pointing to it.

5. **`iterator Find(const std::string& tag)`**:
   - Returns: An iterator pointing to the `XMLElement` with the specified `tag`.
   - Description: Searches for an `XMLElement` within the resource that has the given `tag` and returns an iterator pointing to it.

6. **`bool Erase(iterator it)`**:
   - Returns: `true` if the erasure was successful, `false` if the element specified by the iterator does not exist in the resource.
   - Description: Removes the `XMLElement` pointed to by the provided iterator from the resource. Returns `true` if the erasure was successful, and `false` if the element was not found.
