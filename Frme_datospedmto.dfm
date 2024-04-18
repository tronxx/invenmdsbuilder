object Frame_datospedmto: TFrame_datospedmto
  Left = 0
  Top = 0
  Width = 320
  Height = 182
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 7
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label10: TLabel
    Left = 10
    Top = 30
    Width = 22
    Height = 13
    Caption = 'Folio'
  end
  object Label1: TLabel
    Left = 6
    Top = 55
    Width = 24
    Height = 13
    Caption = 'Serie'
  end
  object Label2: TLabel
    Left = 6
    Top = 79
    Width = 54
    Height = 13
    Caption = 'Serie Motor'
  end
  object Label3: TLabel
    Left = 6
    Top = 103
    Width = 50
    Height = 13
    Caption = 'Pedimento'
  end
  object Label4: TLabel
    Left = 6
    Top = 127
    Width = 37
    Height = 13
    Caption = 'Aduana'
  end
  object Label5: TLabel
    Left = 6
    Top = 151
    Width = 83
    Height = 13
    Caption = 'Fecha Pedimento'
  end
  object edt_codigo: TEdit
    Left = 95
    Top = 5
    Width = 150
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
  end
  object edt_folios: TdxEdit
    Left = 95
    Top = 30
    Width = 150
    TabOrder = 1
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object edt_serie: TEdit
    Left = 95
    Top = 53
    Width = 150
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 20
    TabOrder = 2
  end
  object edt_seriemot: TEdit
    Left = 95
    Top = 77
    Width = 150
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object edt_pedimento: TEdit
    Left = 95
    Top = 101
    Width = 150
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object edt_aduana: TEdit
    Left = 95
    Top = 125
    Width = 150
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 5
  end
  object date_fechaped: TDateTimePicker
    Left = 95
    Top = 148
    Width = 150
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 6
  end
end
