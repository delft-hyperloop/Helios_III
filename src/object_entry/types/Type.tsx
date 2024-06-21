
export type TypeId = "int" | "uint" | "real" | "enum" | "struct"


export interface Type {
  id : TypeId,
  info : TypeInfo
}

export type TypeInfo = IntTypeInfo | UIntTypeInfo | RealTypeInfo | EnumTypeInfo | StructTypeInfo;


export interface IntTypeInfo {
  bit_size : number
}

export interface UIntTypeInfo {
  bit_size : number
}

export interface RealTypeInfo {
  bit_size : number,
  min : number,
  max : number
}

export interface EnumTypeInfo {
  name : string,
  variants : string[]
}

export interface StructTypeInfo {
  name : string,
  attributes : { [name : string] : Type}
}

export function isInt(type: TypeId): type is "int" {
  return type === "int";
}
export function isUInt(type: TypeId): type is "uint" {
  return type === "uint";
}
export function isReal(type: TypeId): type is "real" {
  return type === "real";
}
export function isEnum(type: TypeId): type is "enum" {
  return type === "enum";
}

export function isStruct(type: TypeId): type is "struct" {
  return type === "struct";
}
