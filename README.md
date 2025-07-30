# Env (Environ) Language Overview

**Env** is a lightweight, personal scripting language created for fun and experimentation, it’s built with enough flexibility to power small projects and who knows, maybe something more.

ENV IS IN WIP!

---

## Variables

Variable creation in Env is inspired by JavaScript-like mutability concepts. You define whether a variable is editable or static based on the keyword you use:

### `change`
Creates a **mutable** variable whose value can be updated later.

### `static`
Creates an **immutable** variable whose value cannot be changed once set.

### Example
```env
change Name = "John"
change Age = 25
static Gender = "Male"
```
