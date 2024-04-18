object Frame_datoscambio: TFrame_datoscambio
  Left = 0
  Top = 0
  Width = 627
  Height = 89
  TabOrder = 0
  object lbl_tipo: TLabel
    Left = 24
    Top = 8
    Width = 21
    Height = 13
    Caption = 'Tipo'
  end
  object lbl_idcli: TLabel
    Left = 192
    Top = 8
    Width = 19
    Height = 13
    Caption = 'Idcli'
  end
  object lbl_fecha: TLabel
    Left = 184
    Top = 31
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object lbl_codigo: TLabel
    Left = 13
    Top = 32
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object lbl_sentencia: TLabel
    Left = 2
    Top = 54
    Width = 48
    Height = 13
    Caption = 'Sentencia'
  end
  object edt_tipo: TEdit
    Left = 52
    Top = 4
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object edt_idcli: TEdit
    Left = 220
    Top = 4
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object date_fecha: TDateTimePicker
    Left = 220
    Top = 28
    Width = 122
    Height = 21
    CalAlignment = dtaLeft
    Date = 40652.5432852199
    Time = 40652.5432852199
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
  end
  object edt_codigo: TEdit
    Left = 52
    Top = 28
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object edt_sentencia: TEdit
    Left = 52
    Top = 52
    Width = 501
    Height = 21
    TabOrder = 4
  end
  object chk_ejecutar: TCheckBox
    Left = 352
    Top = 8
    Width = 129
    Height = 17
    Caption = 'Ejecutar la Sentencia'
    TabOrder = 5
  end
end
